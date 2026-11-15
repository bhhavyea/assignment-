#include <stdio.h>

int validateMarks(int mark, int moderation, int *finalMark)
{
    int result;

    if(mark < 0 || mark > 100 ||
       moderation < 0 || moderation > 5)
        return 0;

    result = mark + moderation;

    if(result > 100)
        result = 100;

    *finalMark = result;

    return 1;
}

int checkEligibility(int attendance)
{
    if(attendance < 75 || attendance > 100)
        return 0;

    return 1;
}

int assignGrade(int finalMark)
{
    if(finalMark >= 85)
        return 1;
    else if(finalMark >= 70)
        return 2;
    else if(finalMark >= 50)
        return 3;
    else
        return 4;
}

int calculateGrade(int mark, int attendance,
                   int moderation,
                   int *finalMark, int *reason)
{
    int result;
    int reasonCode;
    int grade;

    if(finalMark == NULL || reason == NULL)
        return -1;

    if(finalMark == reason)
        return -2;

    if(attendance < 0 || attendance > 100 ||
       !validateMarks(mark, moderation, &result))
    {
        *finalMark = -1;
        *reason = 1;
        return -1;
    }

    if(!checkEligibility(attendance))
    {
        *finalMark = result;
        *reason = 2;
        return 0;
    }

    grade = assignGrade(result);

    reasonCode = 0;

    *finalMark = result;
    *reason = reasonCode;

    return grade;
}

int main()
{
    int finalMark, reason, grade;
    int value;

    grade = calculateGrade(80, 85, 5,
                           &finalMark, &reason);

    printf("Final Marks = %d\n", finalMark);
    printf("Reason Code = %d\n", reason);

    if(grade == 1)
        printf("Grade = A\n");
    else if(grade == 2)
        printf("Grade = B\n");
    else if(grade == 3)
        printf("Grade = C\n");
    else if(grade == 4)
        printf("Grade = F\n");
    else if(grade == 0)
        printf("Ineligible\n");
    else
        printf("Invalid input or pointer\n");

    /* Aliasing test */

    value = 10;

    grade = calculateGrade(80, 85, 5,
                           &value, &value);

    if(grade == -2)
        printf("Aliasing rejected\n");

    printf("Value = %d\n", value);

    return 0;
}
