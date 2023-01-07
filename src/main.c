#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cicada/utils.h"
#include "cicada/prime.h"
#include "cicada/analyze.h"
/*
    Program made to help analyze a given string/number for LiberPrimus
    Compiling and executing with gcc: gcc main.c cicada/*.c -o a.exe
*/

#define MAX_LENGTH_VALUE 500

// Entry point
int main(int argc, char const *argv[]) {
    char value[MAX_LENGTH_VALUE] = "";
    value[MAX_LENGTH_VALUE - 1] = '\0';
    
    // Check if fast analyze
    int fastAnalyze = checkFastAnalyze(&argc);
    if (fastAnalyze == 1){
        system("cls");
        strcpy(value, argv[1]);
        analyzeValue(value);
        getchar();
    }
    
    do {
        system("cls");
        
        printf("VALUE: ");
        fflush(stdin);  // Flush the input buffer
        fgets(value, MAX_LENGTH_VALUE, stdin);
        
        // Null-terminate string
        // TODO
        int length = strlen(value);
        if (value[length - 1] == '\n') {
            value[length - 1] = '\0';
        }

        analyzeValue(value);
        getchar();
    } while (strncmp(value, "0", 1) != 0);

    return 3301; // 0
}