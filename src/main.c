#include <stdio.h>
#include "utils.h"
/*
    Program made to help analyze numbers for on Cicada3301
    Compiling and executing with gcc: gcc main.c utils.c | ./a.exe
*/

// Entry point
int main(int argc, char const *argv[])
{
    int fastAnalyze = checkFastAnalyze(&argc);
    
    // Check if fast analyze
    printf("%d", fastAnalyze);
    return 0;
}
