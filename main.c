#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 100
#define MAX_TIME_SIZE 10

int main()
{
    FILE *file_ptr;
    char tme[MAX_TIME_SIZE];
    char str[MAX_EVENT_SIZE];
    int minutes, hour;

    file_ptr = fopen("to-do-list.txt", "w");

    if (file_ptr == NULL)
    {
        printf("Error opening file!");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("Enter Time (HH:MM): ");
        fgets(tme, sizeof(tme), stdin);
        int minutes, hour;

        if (sscanf(tme, "%d:%d", &hour, &minutes) != 2 || (hour < 0 || hour > 23) || (minutes < 0 || minutes > 59))
        {
            printf("Invalid Time Format !\n");
            continue;
        }

        printf("Enter Event: ");
        fgets(str, sizeof(str), stdin);

        tme[strlen(tme) - 1] = '\0';
        str[strlen(str) - 1] = '\0';

        fprintf(file_ptr, "%s :- %s\n", tme, str);

        printf("Do you wish to add another event (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;

        while (getchar() != '\n')
            ;
        printf("\n");
    }
    fclose(file_ptr);
    return 0;
}
