#include <string.h>
#include <ctype.h>
#include "utils.h"

// Fast analyze happens when a number is passed through cmd arguments
// returns boolean flag
int checkFastAnalyze(int *argc){
    return *argc == 2;
}

// Checks if a string is a digit
int strIsDigit(char *str){
    int strLen = strlen(str);
    int result = 1;

    for (int i = 0; i < strLen && result == 1; i++){
        if (!isdigit(str[i]))
            result = 0;
    }
    
    return result;
}