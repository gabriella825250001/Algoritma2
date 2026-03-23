#include <stdio.h>
#include <string.h>

typedef struct student {
    char name [50];
    int student_id;
    float gpa;
} student;

int main (){
    struct student student_01;
    struct student student_02;
    struct student student_03;

    strcpy(student_01.name, "Edward Mercer");
    student_01.student_id = 1001;
    student_01.gpa = 3.85;

    printf("Name: %s\n", student_01.name);
    printf("ID  : %d\n", student_01.student_id);
    printf("GPA : %.1f\n", student_01.gpa);

    return 0;
}