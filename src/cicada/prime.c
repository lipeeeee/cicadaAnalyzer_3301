#include <math.h>
#include "utils.h"

int isPrime(int *num) {
    int result = 1;

    // Prime number has to be over or equal to 2
    if (*num < 2) {
        int sqrt_n = (int) sqrt(*num);
        for (int i = 2; i <= sqrt_n && result == 1; i++) {
            if (*num % i == 0)
                result = 0;
        }
    } 
    else
        result = 0;
    
    return result;
}

/*int isEmirp(int *num) {

}*/