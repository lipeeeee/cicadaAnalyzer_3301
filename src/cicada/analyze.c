#include <string.h>
#include <stdlib.h>
#include "utils.h"

void analyzeValue(char* value);
void analyzeString(char* str);
void analyzeNumber(int num);

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