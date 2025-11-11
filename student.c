#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

struct Student* createStudent(int roll, char name[], float marks) {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

void addStudent() {
    int roll;
    char name[30];
    float marks;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter marks: ");
    scanf("%f", &marks);

    struct Student *newNode = createStudent(roll, name, marks);

    if(head == NULL) {
        head = newNode;
    } else {
        struct Student *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

void displayStudents() {
    if(head == NULL) {
        printf("No records available.\n");
        return;
    }

    struct Student *temp = head;
    printf("\n--- Student Records ---\n");
    while(temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

void searchStudent() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while(temp != NULL) {
        if(temp->roll == roll) {
            printf("Record Found:\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n", temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found.\n");
}

void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    struct Student *prev = NULL;

    while(temp != NULL) {
        if(temp->roll == roll) {
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Student deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Record not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
