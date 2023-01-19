#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cicada/cicada.h"
#include "main.h"

/*
    Program made to help analyze a given string/number for LiberPrimus
    Compiling and executing with gcc: gcc ./*.c cicada/*.c -o a.exe
*/

#define MAX_LENGTH_VALUE 500

// Entry point
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    char value[MAX_LENGTH_VALUE] = "";
    value[MAX_LENGTH_VALUE - 1] = '\0';

    // Check if fast analyze
    int fastAnalyze = checkFastAnalyze(&argc);
    if (fastAnalyze == 1)
    {
        system("cls");
        strcpy(value, argv[1]);
        analyzeValue(value);
        getchar();
    }
    do
    {
        system("cls");

        printf("VALUE: ");
        fflush(stdin); // Flush the input buffer
        if (fgets(value, MAX_LENGTH_VALUE, stdin) != NULL)
        {
            // Null-terminate the string
            value[strcspn(value, "\n")] = '\0';
            /*printf("\nYou entered: %s\n", value);
            printf("Length of the string: %lu\n", strlen(value));*/

            analyzeValue(value);
            getchar();
        }
        else
            printf("The input stream has reached the end-of-file.\n");
    } while (strncmp(value, "0", 1) != 0);

    return 3301; // 0
}