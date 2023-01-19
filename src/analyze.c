#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cicada/cicada.h"
#include "main.h"

/*
    File to help with organizing code and keeping
    main.c file clean.
*/

// Compute blake2b hash to hexString
char *computeHash(char *str)
{
    size_t input_str_len = strlen(str);

    // computed hash
    unsigned char hash[BLAKE2B_OUTBYTES];
    char *hex_hash = malloc(BLAKE2B_OUTBYTES * 2 + 1);
    int ret = blake2b(hash, BLAKE2B_OUTBYTES, str, input_str_len, NULL, 0);

    if (ret == 0)
    {
        // convert the hash to hex string
        for (int i = 0; i < BLAKE2B_OUTBYTES; i++)
        {
            sprintf(hex_hash + (i * 2), "%02x", hash[i]);
        }
    }
    else
    {
        printf("Error occurred while hashing the string\n");
    }

    return hex_hash;
    free(hex_hash);
}

void computeGematria()
{
    struct GematriaLetter *gematria_alphabet = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 1);
    init_gematria_alphabet(gematria_alphabet);
    printf("rune: %lc", gematria_alphabet[0].rune);

    //free_gematria_alphabet(gematria_alphabet);
}

void analyzeString(char *str)
{
    // Blake2b
    char *hex_hash = computeHash(str);
    printf("Blake2B: %s\n", hex_hash);

    // compare the hex string and the computed hash
    if (strcmp(hex_hash, DEEPWEB_HASH) == 0)
    {
        printf("The hash matches the deepweb hash!!\n");
        printf("Notify someone in the cicadaSolvers discord immediatly with this string: %s", str);
    }

    // Gematria
    computeGematria();
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