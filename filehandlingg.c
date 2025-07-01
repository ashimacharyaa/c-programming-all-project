#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s[5];
    FILE *fp;
    int i;

    // Accepting data from user
    printf("Enter name, roll number, and marks of 5 students:\n");
    for (i = 0; i < 2; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Writing data to file
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "Name\t\tRoll\tMarks\n");
    fprintf(fp, "-------------------------------\n");
    for (i = 0; i < 2; i++) {
        fprintf(fp, "%s\t%d\t%f\n", s[i].name, s[i].roll, s[i].marks);
    }

    fclose(fp);

    // Reading and displaying file content
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char ch;
    printf("\nContents of students.txt:\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}
