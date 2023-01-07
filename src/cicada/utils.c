#include <string.h>

// Fast analyze happens when a number is passed through cmd arguments
// returns boolean flag
int checkFastAnalyze(int *argc) {
    return *argc == 2;
}

// Checks if a string is a digit
int strIsDigit(char *str) {
    int strLen = strlen(str);
    int result = 1;

    for (int i = 0; i < strLen && result == 1; i++) {
        if (str[i] < '0' || str[i] > '9')
            result = 0;
    }
    
    return result;
}

// Reverse a given integer
int reverseNumber(int num) {
    int reversed = 0;
    int last_digit = 0;

    while (num != 0) {
        last_digit = num % 10;
        reversed = reversed * 10 + last_digit;
        num /= 10;
    }
    
    return reversed;
}