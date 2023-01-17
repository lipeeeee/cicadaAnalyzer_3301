#include "stdlib.h"

/*
    GEMATRIA PRIMUS
*/
#define MAX_TRANSLATIONS 2
struct GematriaLetter
{
    int order;               // rune order
    char rune;               // rune
    int value;               // numerical value of the letter
    int letter_count;        // english translation
    char **letter;           // english letter lenght(could be either 1 or 2)
    int atbash_order;        // atbash order of the letter
    char atbash_rune;        // atbash rune of the letter
    int atbash_value;        // atbash value of the letter decimal[i] = 28 - decimal[i]
    int atbash_letter_count; // atbash translation
    char **atbash_letter;    // atbash letter length(could be either 1 or 2)
};

// constructor for the struct
struct GematriaLetter *create_gematria_letter(int order, char rune, int value, char *letter, int letter_count, int atbash_order, char atbash_rune, int atbash_value, char *atbash_letter, int atbash_letter_count)
{
    struct GematriaLetter *g = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter));
    g->order = order;
    g->rune = rune;
    g->value = value;
    g->letter_count = letter_count;
    g->letter = (char **)malloc(letter_count * sizeof(char *));
    for (int i = 0; i < letter_count; i++)
    {
        g->letter[i] = (char *)malloc(2 * sizeof(char));
        g->letter[i][0] = letter[i];
    }
    g->atbash_order = atbash_order;
    g->atbash_rune = atbash_rune;
    g->atbash_value = atbash_value;
    g->atbash_letter_count = atbash_letter_count;
    g->atbash_letter = (char **)malloc(atbash_letter_count * sizeof(char *));
    for (int i = 0; i < atbash_letter_count; i++)
    {
        g->atbash_letter[i] = (char *)malloc(2 * sizeof(char));
        g->atbash_letter[i][0] = atbash_letter[i];
    }
    return g;
}

// Building Gematria
struct GematriaLetter *gematria_alphabet /*= (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 32);*/;

void free_gematria_alphabet()
{
    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < gematria_alphabet[i].letter_count; j++)
        {
            if (gematria_alphabet[i].letter[j])
            {
                free(gematria_alphabet[i].letter[j]);
                gematria_alphabet[i].letter[j] = NULL;
            }
        }
        if (gematria_alphabet[i].letter)
        {
            free(gematria_alphabet[i].letter);
            gematria_alphabet[i].letter = NULL;
        }
        for (int j = 0; j < gematria_alphabet[i].atbash_letter_count; j++)
        {
            if (gematria_alphabet[i].atbash_letter[j])
            {
                free(gematria_alphabet[i].atbash_letter[j]);
                gematria_alphabet[i].atbash_letter[j] = NULL;
            }
        }
        if (gematria_alphabet[i].atbash_letter)
        {
            free(gematria_alphabet[i].atbash_letter);
            gematria_alphabet[i].atbash_letter = NULL;
        }
    }
}
