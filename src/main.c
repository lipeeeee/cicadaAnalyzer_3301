#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "cicada/prime.h"

/*
    Program made to help analyze a given string/number for LiberPrimus
    Compiling and executing with gcc: gcc main.c utils.c
                                      ./a.exe
*/

#define MAX_LENGTH_VALUE 500

void analyzeValue(char* str);
void analyzeString(char* str);
void analyzeNumber(int num);

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

        analyzeValue(value);
        getchar();
    } while (strncmp(value, "0", 1) != 0);

    return 3301; // 0
}

void analyzeValue(char* value) {
    int valueIsDigit = strIsDigit(value);
    
    if (valueIsDigit == 1) {
        analyzeNumber(atoi(value));
    } else {
        analyzeString(value);
    }
}

void analyzeString(char* str) {

}

void analyzeNumber(int num) {

}