#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void showMenu();
void addStudent();
void viewStudents();

int main() {
    showMenu();
    return 0;
}

// Displays the menu and handles user choice
void showMenu() {
    int choice;

    do {
        printf("\n===== STUDENT RECORDS MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. View Student Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                printf("Program exited successfully.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}

// Saves student details into a file
void addStudent() {
    FILE *file;
    int admissionNumber;
    char name[50];
    float marks;

    file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("\nEnter Admission Number: ");
    scanf("%d", &admissionNumber);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Marks: ");
    scanf("%f", &marks);

    fprintf(file,
            "Admission Number: %d\nName: %s\nMarks: %.2f\n\n",
            admissionNumber, name, marks);

    fclose(file);

    printf("Student record saved successfully.\n");
}

// Reads and displays data from the file
void viewStudents() {
    FILE *file;
    char ch;

    file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n===== SAVED STUDENT RECORDS =====\n");

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
