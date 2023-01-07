#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
/*
    Program made to help analyze a given string/number for LiberPrimus
    Compiling and executing with gcc: gcc main.c utils.c | ./a.exe
*/

#define MAX_LENGTH_VALUE 50

// Value
char value[MAX_LENGTH_VALUE] = "";
int valueIsDigit = 0;

// Entry point
int main(int argc, char const *argv[])
{
    // Check if fast analyze
    int fastAnalyze = checkFastAnalyze(&argc);
    if (fastAnalyze == 1){
        strcpy(value, argv[1]);
        valueIsDigit = strIsDigit(value);
        
        printf("%s", &value);
        printf("\n%d", valueIsDigit);
    }

    return 0;
}
