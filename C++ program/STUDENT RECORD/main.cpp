#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Student
{
    int id;
    string name;
    int yearOfStudy;
    string program;
    string status; // Active/Inactive
    int numSubjects;
    string *subjects;
    float *grades;
    Student *next;

    Student(int numSub)
    {
        numSubjects = numSub;
        subjects = new string[numSubjects];
        grades = new float[numSubjects];
    }

    ~Student()
    {
        delete[] subjects;
        delete[] grades;
    }
};

class StudentRecord
{
private:
    Student *head;
    const string filePath = "students.txt";

public:
    StudentRecord() : head(nullptr) {}

    void addStudent()
    {
        int numSubjects;
        int id;
        string name, program, status;
        int yearOfStudy;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Year of Study: ";
        cin >> yearOfStudy;
        cin.ignore();
        cout << "Enter Program: ";
        getline(cin, program);
        cout << "Enter Status (Active/Inactive): ";
        getline(cin, status);
        cout << "Enter number of subjects: ";
        cin >> numSubjects;
        cin.ignore();

        Student *newStudent = new Student(numSubjects);
        newStudent->id = id;
        newStudent->name = name;
        newStudent->yearOfStudy = yearOfStudy;
        newStudent->program = program;
        newStudent->status = status;

        for (int i = 0; i < numSubjects; i++)
        {
            cout << "Enter subject " << i + 1 << ": ";
            getline(cin, newStudent->subjects[i]);

            cout << "Enter grade for " << newStudent->subjects[i] << ": ";
            while (!(cin >> newStudent->grades[i]) || newStudent->grades[i] < 0 || newStudent->grades[i] > 100)
            {
                cout << "Invalid grade! Enter again (0-100): ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin.ignore();
        }

        newStudent->next = head;
        head = newStudent;

        saveToFile(*newStudent);
        cout << "Student added successfully!\n";
    }

    void displayStudents()
    {
        if (head == nullptr)
        {
            cout << "No student records found!\n";
            return;
        }

        Student *temp = head;
        while (temp)
        {
            cout << "ID: " << temp->id << "\nName: " << temp->name
                 << "\nYear: " << temp->yearOfStudy << "\nProgram: " << temp->program
                 << "\nStatus: " << temp->status << "\nSubjects and Grades:\n";

            for (int i = 0; i < temp->numSubjects; i++)
            {
                cout << temp->subjects[i] << ": " << temp->grades[i] << "\n";
            }
            cout << "---------------------------------\n";
            temp = temp->next;
        }
    }

    void saveToFile(Student &student)
    {
        ofstream file(filePath, ios::app);
        if (!file)
        {
            cout << "Error opening file for writing!\n";
            return;
        }

        file << "---------------------------------\n";
        file << "ID: " << student.id << "\nName: " << student.name
             << "\nYear: " << student.yearOfStudy << "\nProgram: " << student.program
             << "\nStatus: " << student.status << "\nSubjects and Grades:\n";

        for (int i = 0; i < student.numSubjects; i++)
        {
            file << student.subjects[i] << ": " << student.grades[i] << "\n";
        }

        file.close();
    }

    void sortGradesForStudent()
    {
        int searchID;
        cout << "Enter student ID to sort grades: ";
        cin >> searchID;

        Student *temp = head;
        while (temp)
        {
            if (temp->id == searchID)
            {
                cout << "Sorting grades for " << temp->name << "...\n";
                bubbleSort(temp->grades, temp->subjects, temp->numSubjects);
                cout << "Grades sorted successfully!\n";
                displayStudentGrades(*temp);
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    void bubbleSort(float grades[], string subjects[], int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (grades[j] > grades[j + 1])
                {
                    swap(grades[j], grades[j + 1]);
                    swap(subjects[j], subjects[j + 1]);
                }
            }
        }
    }

    void displayStudentGrades(Student &student)
    {
        cout << "\nGrades for " << student.name << ":\n";
        for (int i = 0; i < student.numSubjects; i++)
        {
            cout << student.subjects[i] << ": " << student.grades[i] << "\n";
        }
    }

    void searchStudent()
    {
        int searchID;
        cout << "Enter student ID to search: ";
        cin >> searchID;

        Student *temp = head;
        while (temp)
        {
            if (temp->id == searchID)
            {
                cout << "Student Found!\n";
                cout << "ID: " << temp->id << "\nName: " << temp->name
                     << "\nYear: " << temp->yearOfStudy << "\nProgram: " << temp->program
                     << "\nStatus: " << temp->status << "\nSubjects and Grades:\n";
                for (int i = 0; i < temp->numSubjects; i++)
                {
                    cout << temp->subjects[i] << ": " << temp->grades[i] << "\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    void updateStudent()
    {
        int searchID;
        cout << "Enter student ID to update: ";
        cin >> searchID;

        Student *temp = head;
        while (temp)
        {
            if (temp->id == searchID)
            {
                cout << "Updating details for " << temp->name << "...\n";
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, temp->name);
                cout << "Enter new program: ";
                getline(cin, temp->program);
                cout << "Enter new status (Active/Inactive): ";
                getline(cin, temp->status);
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    void deleteStudent()
    {
        int searchID;
        cout << "Enter student ID to delete: ";
        cin >> searchID;

        Student *temp = head;
        Student *prev = nullptr;
        while (temp)
        {
            if (temp->id == searchID)
            {
                if (prev)
                {
                    prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }
                delete temp;
                cout << "Student deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    void calculateAverageGrade()
    {
        int searchID;
        cout << "Enter student ID to calculate average grade: ";
        cin >> searchID;

        Student *temp = head;
        while (temp)
        {
            if (temp->id == searchID)
            {
                float sum = 0;
                for (int i = 0; i < temp->numSubjects; i++)
                {
                    sum += temp->grades[i];
                }
                float average = sum / temp->numSubjects;
                cout << "Average grade for " << temp->name << ": " << average << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    void menu()
    {
        int choice;
        do
        {
            cout << "\nStudent Record Management System\n";
            cout << "1. Add Student\n2. Display Students\n3. Sort Student Grades\n4. Search Student\n5. Update Student\n6. Delete Student\n7. Calculate Average Grade\n8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                sortGradesForStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                calculateAverageGrade();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 8);
    }
};

int main()
{
    StudentRecord sr;
    sr.menu();
    return 0;
}
