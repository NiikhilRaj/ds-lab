#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int roll;
    char name[50];
    char gender[10];
    int marks;
};

int main()
{
    char studentName[50];
    char genderm[10];

    struct student *student= (struct student *)malloc(sizeof(struct student));
    printf("Enter rollno: ");
    scanf("%d", student->roll);

    printf("Enter Name: ");;
    scanf("%s", studentName);

    printf("Enter Gender: ");
    scanf("%s", genderm);

    printf("Enter marks: ");
    scanf("%d", student->marks);

    strcpy(student->name, studentName);
    strcpy(student->gender, genderm);

    printf("\n Name- %s, Rollno- %d, Gender- %s, Marks- %d\n", student->name, student->roll, student->gender, student->marks);
    
    return 0;
}