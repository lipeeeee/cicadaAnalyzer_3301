#include "stdlib.h"

/*
    GEMATRIA PRIMUS
*/

struct GematriaLetter
{
    int order;          // rune order
    char* letter;       // english translation
    int letter_len;     // english letter lenght(could be either 1 or 2)
    char rune;          // rune
    int value;          // numerical value of the letter
    int atbash_value;   // atbash value of the letter
    char atbash_rune;   // atbash rune of the letter
    char *atbash_letter;// atbash translation
    int atbash_len;     // atbash letter length(could be either 1 or 2)
    int atbash_order;   // atbash order of the letter
};
struct GematriaLetter *new_GematriaLetter(int order, char letter, char rune, int value, int atbash_value, char atbash_rune, char atbash_letter, int atbash_order)
{
    struct GematriaLetter *res = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter));
    res->order = order;
    res->letter = letter;
    res->rune = rune;
    res->value = value;
    res->atbash_value = atbash_value;
    res->atbash_rune = atbash_rune;
    res->atbash_letter = atbash_letter;
    res->atbash_order = atbash_order;
    return res;
}

// Building Gematria
struct GematriaLetter *gemAlphabet /*= (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 29);*/;

void init_gematria_alphabet()
{
    // initialize the alphabet
    gemAlphabet = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 29);

    // fill the alphabet
    struct GematriaLetter *temp = new_GematriaLetter(0 ,'F', 'ᚨ', 1, 1, 'ᚦ', 'T', 20);
    gemAlphabet[0] = *temp;
    free(temp);
    struct GematriaLetter *temp = new_GematriaLetter(1, 'B', 'ᛠ', 1, 1, 'ᚦ', 'T', 20);
    gemAlphabet[1] = *temp;
    free(temp);
}

