#include <windows.h>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
#define ID_EDIT 1
#define ID_UNDO 2
#define ID_REDO 3
#define ID_SAVE 4
#define ID_DELETE_WORD 5
class TextEditor
{
private:
    wstring currentText;
    stack<wstring> undoStack;
    stack<wstring> redoStack;
    HWND hwnd;
    HINSTANCE hInstance;
    HWND hEdit;
    HWND hUndoButton;
    HWND hRedoButton;
    HWND hSaveButton;
    HWND hDeleteWordButton;

public:
    TextEditor(HINSTANCE hInst, HWND hWnd) : hInstance(hInst), hwnd(hWnd)
    {
        //loadFromFile();
        createControls();
    }

    void loadFromFile()
    {
        wifstream file(L"saved_text.txt");
        if (file.is_open())
        {
            wstring line;
            while (getline(file, line))
            {
                currentText += line + L"\n";
            }
            file.close();
        }
    }

    void createControls()
    {
        hEdit = CreateWindowExW(
            0, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | WS_BORDER,
            10, 40, 760, 400, hwnd, (HMENU)ID_EDIT, hInstance, NULL);

        // Set the border color to blue
        SetWindowLongW(hEdit, GWL_EXSTYLE, GetWindowLongW(hEdit, GWL_EXSTYLE) | WS_EX_CLIENTEDGE);
        SetWindowPos(hEdit, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);

        hUndoButton = CreateWindowExW(
            0, L"BUTTON", L"Undo",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 10, 80, 25, hwnd, (HMENU)ID_UNDO, hInstance, NULL);

        hRedoButton = CreateWindowExW(
            0, L"BUTTON", L"Redo",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            100, 10, 80, 25, hwnd, (HMENU)ID_REDO, hInstance, NULL);

        hSaveButton = CreateWindowExW(
            0, L"BUTTON", L"Save",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            190, 10, 80, 25, hwnd, (HMENU)ID_SAVE, hInstance, NULL);

        hDeleteWordButton = CreateWindowExW(
            0, L"BUTTON", L"Delete Word",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            280, 10, 100, 25, hwnd, (HMENU)ID_DELETE_WORD, hInstance, NULL);

        SetWindowTextW(hEdit, currentText.c_str());
    }

    void typeText(wchar_t c)
    {
        undoStack.push(currentText);
        currentText += c;
        while (!redoStack.empty())
            redoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void deleteText()
    {
        if (currentText.empty())
            return;
        undoStack.push(currentText);
        currentText.pop_back();
        while (!redoStack.empty())
            redoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void deleteWord()
    {
        if (currentText.empty())
            return;
        undoStack.push(currentText);
        size_t pos = currentText.find_last_of(L" ");
        currentText = (pos == wstring::npos) ? L"" : currentText.substr(0, pos);
        while (!redoStack.empty())
            redoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void undo()
    {
        if (undoStack.empty())
            return;
        redoStack.push(currentText);
        currentText = undoStack.top();
        undoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void redo()
    {
        if (redoStack.empty())
            return;
        undoStack.push(currentText);
        currentText = redoStack.top();
        redoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void pressEnter()
    {
        undoStack.push(currentText);
        currentText += L"\n";
        while (!redoStack.empty())
            redoStack.pop();
        SetWindowTextW(hEdit, currentText.c_str());
    }

    void saveToFile()
    {
        wofstream file(L"saved_text.txt");
        if (file.is_open())
        {
            file << currentText;
            file.close();
        }
    }

    void handleCommand(WPARAM wParam)
    {
        switch (LOWORD(wParam))
        {
        case ID_UNDO:
            undo();
            break;
        case ID_REDO:
            redo();
            break;
        case ID_SAVE:
            saveToFile();
            break;
        case ID_DELETE_WORD:
            deleteWord();
            break;
        }
    }

    void handleKeyPress(WPARAM wParam, LPARAM lParam)
    {
        bool ctrlPressed = (GetKeyState(VK_CONTROL) & 0x8000) != 0;

        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        case 'Z':
            if (ctrlPressed)
                undo();
            break;
        case 'Y':
            if (ctrlPressed)
                redo();
            break;
        case 'D':
            if (ctrlPressed)
                deleteWord();
            break;
        case VK_BACK:
            deleteText();
            break;
        case VK_RETURN:
            pressEnter();
            break;
        case 'S':
            if (ctrlPressed)
                saveToFile();
            break;
        default:
            if (wParam >= 32 && wParam <= 126)
                typeText(static_cast<wchar_t>(wParam));
            break;
        }
    }
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static TextEditor* editor = nullptr;

    switch (uMsg)
    {
    case WM_CREATE:
        editor = new TextEditor(GetModuleHandle(NULL), hwnd);
        break;
    case WM_COMMAND:
        editor->handleCommand(wParam);
        break;
    case WM_CHAR:
        editor->handleKeyPress(wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"TextEditorClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Show the mouse cursor

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Text Editor",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
