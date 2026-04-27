#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure definition
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent(struct Student s[], int *count);
void viewStudents(struct Student s[], int count);
void searchStudent(struct Student s[], int count);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}

// Function to add student
void addStudent(struct Student s[], int *count) {
    if (*count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &s[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents(struct Student s[], int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
        printf("----------------------\n");
    }
}

// Function to search student by ID
void searchStudent(struct Student s[], int count) {
    int id, found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}
