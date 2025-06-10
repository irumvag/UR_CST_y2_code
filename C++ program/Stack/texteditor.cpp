#include <iostream>
#include <ncurses.h>
#include <stack>
#include <string>
using namespace std;
class TextEditor {
private:
    string currentText; // Current text in the editor
    stack<string> undoStack; // Stack for undo history
    stack<string> redoStack; // Stack for redo history
public:
    // Constructor: Initializes ncurses and setup window
    void init() {
        initscr();          // Start ncurses
        raw();              // Disable line buffering
        keypad(stdscr, TRUE); // Enable special keys like arrows
        noecho();           // Don't show typed characters
        curs_set(1);        // Make the cursor visible
        refresh();
    }
    // Destructor: End ncurses session
    void end() {
        endwin();  // End ncurses mode
    }
    // Add a character to the current text
    void typeText(char c) {
        undoStack.push(currentText);  // Save current text for undo
        currentText += c;             // Append the typed character to the text
        while (!redoStack.empty()) {
            redoStack.pop();  // Clear redo stack on new input
        }
    }
    // Delete the last character in the current text
    void deleteText() {
        if (currentText.empty()) return;
        undoStack.push(currentText);  // Save current text for undo
        currentText.pop_back();       // Remove the last character
        while (!redoStack.empty()) {
            redoStack.pop();  // Clear redo stack on new input
        }
    }
    // Undo the last action
    void undo() {
        if (undoStack.empty()) return;
        redoStack.push(currentText);  // Save the current text to redo stack
        currentText = undoStack.top(); // Revert to the previous state
        undoStack.pop();
    }
    // Redo the last undone action
    void redo() {
        if (redoStack.empty()) return;
        undoStack.push(currentText);  // Save current state to undo stack
        currentText = redoStack.top(); // Revert to the redone state
        redoStack.pop();
    }
    // Get the current text
     string getText() const {
        return currentText;
    }
    // Display the text in the ncurses window
    void displayText() {
        clear();  // Clear the window
        mvprintw(0, 0, "Text Editor: Type, Undo (Ctrl+Z), Redo (Ctrl+Y), Exit (Ctrl+C)");
        // Display the current text
        mvprintw(2,0,"-------------------------------------------------------------------");
        mvprintw(4, 0, currentText.c_str());
        refresh();  // Refresh the window to show changes
    }
};
int main() {
    TextEditor editor;
    editor.init();  // Initialize ncurses
    char ch;
    bool running = true;
    while (running) {
        editor.displayText();  // Display current text in the window
        ch = getch();  // Get user input
        switch (ch) {
            case 3:  // Ctrl+C: Exit the program
                running = false;
                break;
            case 26:  // Ctrl+Z: Undo
                editor.undo();
                break;
            case 25:  // Ctrl+Y: Redo
                editor.redo();
                break;
            case 127:  // Backspace (delete)
                editor.deleteText();
                break;
            default:
                if (ch >= 32 && ch <= 126) {  // Printable characters
                    editor.typeText(ch);
                }
                break;
        }
    }
    editor.end();  // End ncurses
    return 0;
}
