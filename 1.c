#include <stdio.h>

int main()
{
    int n, i, mark, roll;
    int min = 101, max = -1;
    int minRoll = -1, maxRoll = -1;
    int minCount = 0, maxCount = 0;
    int validCount = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter roll number and marks: ");
        scanf("%d %d", &roll, &mark);

        if(mark == -1)
        {
            printf("Absent\n");
        }
        else if(mark < 0 || mark > 100)
        {
            printf("Invalid marks\n");
        }
        else
        {
            validCount++;

            if(validCount == 1)
            {
                min = max = mark;
                minRoll = maxRoll = roll;
                minCount = maxCount = 1;
            }
            else
            {
                if(mark > max)
                {
                    max = mark;
                    maxRoll = roll;
                    maxCount = 1;
                }
                else if(mark == max)
                {
                    maxCount++;
                }

                if(mark < min)
                {
                    min = mark;
                    minRoll = roll;
                    minCount = 1;
                }
                else if(mark == min)
                {
                    minCount++;
                }
            }
        }
    }

    if(validCount == 0)
    {
        printf("No valid marks found\n");
    }
    else
    {
        printf("\nHighest Marks = %d\n", max);
        printf("Roll Number = %d\n", maxRoll);
        printf("Tie Count = %d\n", maxCount);

        printf("\nLowest Marks = %d\n", min);
        printf("Roll Number = %d\n", minRoll);
        printf("Tie Count = %d\n", minCount);
    }

    return 0;
}
