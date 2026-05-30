#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    long rollNumber;
    float marks;
    float spi;
};

// TO ADD STUDENT
void addStudent(struct Student *students, int *count)
{
    printf("Enter student name: ");
    char name[50];
    scanf("%s", name);
    while (1)
    {
        int valid = 1;

        for (int i = 0; i < strlen(name); i++)
        {
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
            {
                valid = 0;
                break;
            }
        }
        if (valid)
        {
            strcpy(students[*count].name, name);
            break;
        }
        else
        {
            printf("Invalid name. Please enter a valid name: ");
        }
    }

    int rollNumber;
    printf("Enter roll number: ");
    scanf("%d", &rollNumber);
    students[*count].rollNumber = rollNumber;
    float marks;
    while (1)
    {
        printf("Enter marks from 0 to 100: ");
        scanf("%f", &marks);
        if (marks >= 0 && marks <= 100)
        {
            students[*count].marks = marks;
            break;
        }
        else
        {
            printf("Invalid marks. Please enter a number between 0 and 100.\n");
        }
    }

    if (students[*count].marks >= 90)
    {
        students[*count].spi = 10.0;
    }
    else if (students[*count].marks >= 80)
    {
        students[*count].spi = 9.0;
    }
    else if (students[*count].marks >= 70)
    {
        students[*count].spi = 8.0;
    }
    else if (students[*count].marks >= 60)
    {
        students[*count].spi = 7.0;
    }
    else if (students[*count].marks >= 50)
    {
        students[*count].spi = 6.0;
    }
    else if (students[*count].marks >= 40)
    {
        students[*count].spi = 5.0;
    }
    else if (students[*count].marks >= 30)
    {
        students[*count].spi = 4.0;
    }
    else if (students[*count].marks >= 20)
    {
        students[*count].spi = 3.0;
    }
    else
    {
        students[*count].spi = 1.0;
    }

    (*count)++;
    printf("\nStudent added successfully!\n");
}

// TO DISPLAY STUDENT DETAILS
void displayStudents(struct Student *students, int count)
{
    if (count == 0)
    {
        printf("\nNo students in the database.\n");
        return;
    }

    printf("\n\nStudent Database:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Name", "RollNumber", "Marks", "Grade");
    for (int i = 0; i < count; i++)
    {
        printf("%-10s %-10ld %-10.2f %-10.2f\n", students[i].name, students[i].rollNumber, students[i].marks, students[i].spi);
    }
}

// TO DELETE A STUDENT
void deleteStudent(struct Student *students, int *count)
{
    if (*count == 0)
    {
        printf("\nNo students in the database.\n");
        return;
    }

    int rollNumber;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *count; i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            for (int j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// bubble
void sortByName(struct Student *students, int count)
{
    struct Student *sortedStudents = (struct Student *)malloc(count * sizeof(struct Student));
    for (int i = 0; i < count; i++)
    {
        sortedStudents[i] = students[i]; // copy original data
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(sortedStudents[i].name, sortedStudents[j].name) > 0)
            {
                struct Student temp = sortedStudents[i];
                sortedStudents[i] = sortedStudents[j];
                sortedStudents[j] = temp;
            }
        }
    }
    printf("\n\nStudent Database:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Name", "RollNumber", "Marks", "Grade");
    for (int i = 0; i < count; i++)
    {
        printf("%-10s %-10ld %-10.2f %-10.2f\n", sortedStudents[i].name, sortedStudents[i].rollNumber, sortedStudents[i].marks, sortedStudents[i].spi);
    }
}

// Sorting with bubble sort technique
void sortByMarks(struct Student *students, int count)
{
    struct Student *sortedStudents = (struct Student *)malloc(count * sizeof(struct Student));
    for (int i = 0; i < count; i++)
    {
        sortedStudents[i] = students[i]; // copy original data
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (sortedStudents[i].marks < sortedStudents[j].marks)
            {
                struct Student temp = sortedStudents[i];
                sortedStudents[i] = sortedStudents[j];
                sortedStudents[j] = temp;
            }
        }
    }
    printf("\n\nStudent Database (sorted by marks):\n");
    printf("%-10s %-10s %-10s %-10s\n", "Name", "RollNumber", "Marks", "Grade");
    for (int i = 0; i < count; i++)
    {
        printf("%-10s %-10ld %-10.2f %-10.2f\n", sortedStudents[i].name, sortedStudents[i].rollNumber, sortedStudents[i].marks, sortedStudents[i].spi);
    }
    free(sortedStudents); // free the copied data
}

// Sorting with selection sort technique
void sortByRollNumber(struct Student *students, int count)
{
    struct Student *sortedStudents = (struct Student *)malloc(count * sizeof(struct Student));
    for (int i = 0; i < count; i++)
    {
        sortedStudents[i] = students[i]; // copy original data
    }

    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < count; j++)
        {
            if (sortedStudents[j].rollNumber < sortedStudents[minIndex].rollNumber)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            struct Student temp = sortedStudents[i];
            sortedStudents[i] = sortedStudents[minIndex];
            sortedStudents[minIndex] = temp;
        }
    }
    printf("\n\nStudent Database (sorted by roll number):\n");
    printf("%-10s %-10s %-10s %-10s\n", "Name", "RollNumber", "Marks", "Grade");
    for (int i = 0; i < count; i++)
    {
        printf("%-10s %-10ld %-10.2f %-10.2f\n", sortedStudents[i].name, sortedStudents[i].rollNumber, sortedStudents[i].marks, sortedStudents[i].spi);
    }
    free(sortedStudents); // free the copied data
}
int main()
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int count = 0;

    while (1)
    {
        printf("\n-----STUDENT RECORD MANAGEMENT SYSTEM-----\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Delete student\n");
        printf("4. Sort by name\n");
        printf("5. Sort by marks\n");
        printf("6. Sort by roll number\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count < numStudents)
            {
                addStudent(students, &count);
            }
            else
            {
                printf("Maximum number of students reached.\n");
            }
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            deleteStudent(students, &count);
            break;
        case 4:
            sortByName(students, count);
            printf("Students sorted by name successfully!\n");
            break;
        case 5:
            sortByMarks(students, count);
            printf("Students sorted by marks successfully!\n");
            break;
        case 6:
            sortByRollNumber(students, count);
            printf("Students sorted by roll number successfully!\n");
            break;
        case 7:
            printf("Exiting the program...\n");
            free(students);
            return 0;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    free(students);
    return 0;
}