#include <stdio.h>

int main()
{
    int marks[40], roll[40], section[40], pos[40];
    int sm[40], sr[40], ss[40], sp[40];
    int n, i, j, count = 0;
    int temp, queries, key;
    int low, high, mid, first, found;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if(n < 1 || n > 40)
    {
        printf("Invalid size\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter roll number, section and marks: ");
        scanf("%d %d %d", &roll[i], &section[i], &marks[i]);

        pos[i] = i + 1;

        if(marks[i] < -1 || marks[i] > 100)
        {
            printf("Invalid marks\n");
            return 0;
        }

        if(marks[i] != -1)
        {
            sm[count] = marks[i];
            sr[count] = roll[i];
            ss[count] = section[i];
            sp[count] = pos[i];
            count++;
        }
    }

    /* Sort the copy without changing original arrays */

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(sm[j] < sm[j+1] ||
              (sm[j] == sm[j+1] && sp[j] > sp[j+1]))
            {
                temp = sm[j];
                sm[j] = sm[j+1];
                sm[j+1] = temp;

                temp = sr[j];
                sr[j] = sr[j+1];
                sr[j+1] = temp;

                temp = ss[j];
                ss[j] = ss[j+1];
                ss[j+1] = temp;

                temp = sp[j];
                sp[j] = sp[j+1];
                sp[j+1] = temp;
            }
        }
    }

    printf("\nStudent Ranking\n");

    for(i = 0; i < count; i++)
    {
        printf("Rank %d: Roll = %d, Marks = %d, Section = %d, Position = %d\n",
               i+1, sr[i], sm[i], ss[i], sp[i]);
    }

    printf("\nEnter number of search queries: ");
    scanf("%d", &queries);

    for(j = 0; j < queries; j++)
    {
        printf("Enter marks to search: ");
        scanf("%d", &key);

        if(queries == 1)
        {
            found = 0;

            for(i = 0; i < n; i++)
            {
                if(marks[i] == key)
                {
                    printf("Found at position %d\n", pos[i]);
                    found = 1;
                }
            }

            if(found == 0)
                printf("Not found\n");
        }
        else
        {
            low = 0;
            high = count;

            while(low < high)
            {
                mid = (low + high) / 2;

                if(sm[mid] > key)
                    low = mid + 1;
                else
                    high = mid;
            }

            first = low;

            if(first == count || sm[first] != key)
            {
                printf("Not found\n");
            }
            else
            {
                while(first < count && sm[first] == key)
                {
                    printf("Found at original position %d\n", sp[first]);
                    first++;
                }
            }
        }
    }

    return 0;
}
