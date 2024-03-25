#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file_ptr;
    char tme[10];
    char str[100];
    int minutes , hour;


    file_ptr = fopen("to-do-list.txt", "w");

    if (file_ptr == NULL)
    {
        printf("Error opening file!");
        exit(EXIT_FAILURE);
    }


    printf("Enter Time (HH:MM): ");
    fgets(tme, sizeof(tme), stdin);
    if (sscanf(tme, "%d:%d", &hour, &minutes)!= 2 || (hour < 0 || hour > 23) || (minutes < 0 || minutes > 59)){
        printf("Invalid Time Format !\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter Event: ");
    fgets(str, sizeof(str), stdin);

    tme[strlen(tme) - 1] = '\0';
    str[strlen(str) - 1] = '\0';

    fprintf(file_ptr, "%s : %s\n", tme, str);
    fclose(file_ptr);
    return 0;
}
