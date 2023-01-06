#include "utils.h"

// Fast analyze happens when a number is passed through cmd arguments
// returns boolean flag
int checkFastAnalyze(int *argc){
    return *argc == 2;
}