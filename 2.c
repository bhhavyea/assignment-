#include <stdio.h>

int main()
{
    int n, i, mark, attendance, moderation;
    int finalMark, section;
    int grade;
    int count[10][4] = {0};
    int sections;

    printf("Enter number of sections: ");
    scanf("%d", &sections);

    if(sections < 1 || sections > 10)
    {
        printf("Invalid sections\n");
        return 0;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nEnter marks, attendance, moderation and section: ");
        scanf("%d %d %d %d",
              &mark, &attendance, &moderation, &section);

        if(mark < 0 || mark > 100 ||
           attendance < 0 || attendance > 100 ||
           moderation < 0 || section < 0 ||
           section >= sections)
        {
            printf("Invalid input\n");
            continue;
        }

        if(attendance < 75)
        {
            printf("Ineligible\n");
            continue;
        }

        if(moderation > 5)
            moderation = 5;

        finalMark = mark + moderation;

        if(finalMark > 100)
            finalMark = 100;

        if(finalMark >= 85)
        {
            grade = 0;
            printf("Grade A\n");
        }
        else if(finalMark >= 70)
        {
            grade = 1;
            printf("Grade B\n");
        }
        else if(finalMark >= 50)
        {
            grade = 2;
            printf("Grade C\n");
        }
        else
        {
            grade = 3;
            printf("Grade F\n");
        }

        count[section][grade]++;
    }

    printf("\nGrade Count Across Sections\n");

    for(i = 0; i < sections; i++)
    {
        printf("\nSection %d\n", i);

        printf("A = %d\n", count[i][0]);
        printf("B = %d\n", count[i][1]);
        printf("C = %d\n", count[i][2]);
        printf("F = %d\n", count[i][3]);
    }

    return 0;
}
