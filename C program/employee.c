#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char firstName[25];
    char lastName[25];
    char department[50];
    float salary;
};

void writeEmployeeToFile(struct Employee emp, FILE *file) {
    fprintf(file, "%d %s %s %s %.2f\n", emp.id, emp.firstName, emp.lastName, emp.department, emp.salary);
}

void displayEmployees(FILE *file) {
    int i = 1;
    char line[200];
    printf("\n--- Employee List ---\n");
    while (fgets(line, sizeof(line), file)) {
        int id;
        char firstName[25], lastName[25], department[50];
        float salary;
        sscanf(line, "%d %24s %24s %49s %f", &id, firstName, lastName, department, &salary);
        printf("----------------------------\n");
        printf("Employee %d:\n", i++);
        printf("ID: %d\n", id);
        printf("First Name: %s\n", firstName);
        printf("Last Name: %s\n", lastName);
        printf("Department: %s\n", department);
        printf("Salary: %.2f\n", salary);
    }
}

int main() {
    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            FILE *file = fopen("employees.txt", "a");
            if (file == NULL) {
                printf("Failed to open file\n");
                return 1;
            }
            struct Employee emp;
            printf("Enter Employee ID: ");
            scanf("%d", &emp.id);
            printf("Enter Employee First Name: ");
            scanf("%24s", emp.firstName);
            printf("Enter Employee Last Name: ");
            scanf("%24s", emp.lastName);
            printf("Enter Employee Department: ");
            scanf("%49s", emp.department);
            printf("Enter Employee Salary: ");
            scanf("%f", &emp.salary);
            
            writeEmployeeToFile(emp, file);
            fclose(file);
            printf("Employee added successfully!\n");
        }
        else if (choice == 2) {
            FILE *file = fopen("employees.txt", "r");
            if (file == NULL) {
                printf("No employee records found.\n");
            } else {
                displayEmployees(file);
                fclose(file);
            }
        }
    } while (choice != 3);
    
    printf("Exiting program.\n");
    return 0;
}