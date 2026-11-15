#include <stdio.h>
#include <string.h>

int main()
{
    char name[32];
    char *p;
    int ch;

    printf("Enter student name: ");

    if(fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Input error\n");
        return 1;
    }

    p = strchr(name, '\n');

    if(p != NULL)
    {
        *p = '\0';
    }
    else
    {
        ch = getchar();

        if(ch != '\n' && ch != EOF)
        {
            while(ch != '\n' && ch != EOF)
                ch = getchar();

            printf("Name is too long\n");
            return 1;
        }
    }

    printf("Registered Student Name: %s\n", name);

    return 0;
}
