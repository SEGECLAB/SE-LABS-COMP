#include <stdio.h>
#include <stdlib.h>

struct record
{
    int roll_no;
    struct nameSchema
    {
        char first[10];
        char middle[10];
        char last[10];
    } name;
    struct semMarks
    {
        int sub1;
        int sub2;
        int sub3;
        int sub4;
    } sem[2];
};

int gradePoint(int marks)
{
    int gp;
    if (marks >= 85)
    {
        gp = 10;
    }
    else if (marks >= 75)
    {
        gp = 9;
    }

    else if (marks >= 65)
    {
        gp = 8;
    }

    else if (marks >= 55)
    {
        gp = 7;
    }

    else if (marks >= 50)
    {
        gp = 6;
    }

    else if (marks >= 45)
    {
        gp = 5;
    }

    else if (marks >= 40)
    {
        gp = 4;
    }
    else
    {
        gp = 0;
    }
    return gp;
}

float *calcSGPA(struct record r[], int sem, int size)
{

    float *sgpa = (float *)malloc(sizeof(float) * size);
    sem--;
    int percentage;
    int gp1, gp2, gp3, gp4;
    for (int i = 0; i < size; i++)
    {

        gp1 = gradePoint(r[i].sem[sem].sub1);
        gp2 = gradePoint(r[i].sem[sem].sub2);
        gp3 = gradePoint(r[i].sem[sem].sub3);
        gp4 = gradePoint(r[i].sem[sem].sub4);

        sgpa[i] = (float)(gp1 * 4 + gp2 * 3 + gp3 * 3 + gp4 * 3) / (13.0);
    }
    return sgpa;
}

float *calcCGPA(float *sgpa1, float *sgpa2, int size)
{
    float *cgpa = (float *)malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++)
    {
        cgpa[i] = (float)(sgpa1[i] + sgpa2[i]) / 2.0;
    }
    return cgpa;
}

void show(struct record r[], float *sgpa1, float *sgpa2, float *cgpa, int size)
{

    printf("Roll no.\t\t\tNAME\t\t\tSEM1-sgpa\t\tSEM2-sgpa\t\tCGPA\n");
    for (int i = 0; i < size; i++)
    {
        printf("\n");
        printf("%d\t\t\t", r[i].roll_no);
        printf("%s %s %s\t", r[i].name.first, r[i].name.middle, r[i].name.last);
        printf("\t%.2f\t\t", sgpa1[i]);
        printf("\t%.2f\t\t", sgpa2[i]);
        printf("\t%.2f\n", cgpa[i]);
    }
}

int main()
{
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);
    struct record r[size];

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter details for student %d", i + 1);
        printf("\nEnter roll no. : ");
        scanf("%d", &r[i].roll_no);
        printf("Enter name: ");
        scanf("%s%s%s", r[i].name.first, r[i].name.middle, r[i].name.last);
        printf("\nEnter marks for sem 1:");
        printf("\nEnter marks for math, chem,\nbee and mech respectively: ");
        scanf("%d%d%d%d", &r[i].sem[0].sub1, &r[i].sem[0].sub2, &r[i].sem[0].sub3, &r[i].sem[0].sub4);
        printf("\nEnter marks for sem 2:");
        printf("\nEnter marks for math, phy,\ncivil and comp respectively: ");
        scanf("%d%d%d%d", &r[i].sem[1].sub1, &r[i].sem[1].sub2, &r[i].sem[1].sub3, &r[i].sem[1].sub4);
    }

    float *sgpa1 = calcSGPA(r, 1, size);
    float *sgpa2 = calcSGPA(r, 2, size);

    float *cgpa = calcCGPA(sgpa1, sgpa2, size);

    show(r, sgpa1, sgpa2, cgpa, size);

    free(sgpa1);
    free(sgpa2);
    free(cgpa);
    return 0;
}