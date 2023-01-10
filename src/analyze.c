#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cicada/cicada.h"
#include "main.h"

/*
    File to help with organizing code and keeping
    main.c file clean.
*/

void analyzeString(char *str)
{
    // BLAKE2b-512 Hash
    size_t input_str_len = strlen(str);
    unsigned char hash[BLAKE2B_OUTBYTES];
    int ret = blake2b(hash, BLAKE2B_OUTBYTES, str, input_str_len, NULL, 0);

    if (ret == 0)
    {
        printf("BLAKE2b-512: ");
        for (int i = 0; i < BLAKE2B_OUTBYTES; i++)
            printf("%02x", hash[i]);

        printf("\n");

        // Check for the deepweb hash
        if (strncmp((char *)hash, DEEPWEB_HASH, BLAKE2B_OUTBYTES) == 0)
        {
            printf("FOUND DWH((This line of code will never be executed\n");
        }
    }
    else
    {
        printf("BLAKE2b-512: Error occurred while hashing the string\n");
    }
}

void analyzeNumber(int num)
{
    printf("isPrime(): %d", isPrime(&num));
}

void analyzeValue(char *value)
{
    int valueIsDigit = strIsDigit(value);

    if (valueIsDigit == 1)
    {
        analyzeNumber(atoi(value));
    }
    else
    {
        analyzeString(value);
    }
}