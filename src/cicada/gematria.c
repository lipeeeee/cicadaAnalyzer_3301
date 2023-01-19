#include "stdlib.h"
#include "string.h"
#include "cicada.h"
#include "wchar.h"

#define MAX_TRANSLATIONS 2
#define MAX_TRANSLATION_LENGTH 3

// constructor for the struct
struct GematriaLetter create_gematria_letter(int order, wchar_t rune, int value, int letter_count, char (*letter)[MAX_TRANSLATION_LENGTH], int atbash_order, wchar_t atbash_rune, int atbash_value, int atbash_letter_count, char (*atbash_letter)[MAX_TRANSLATION_LENGTH])
{
    struct GematriaLetter new_letter;
    new_letter.order = order;
    new_letter.rune = rune;
    new_letter.value = value;
    new_letter.letter_count = letter_count;
    new_letter.letter = (char **)malloc(letter_count * sizeof(char *));
    for (int i = 0; i < letter_count; i++)
    {
        new_letter.letter[i] = (char *)malloc(MAX_TRANSLATION_LENGTH * sizeof(char));
        strcpy(new_letter.letter[i], letter[i]);
    }
    new_letter.atbash_order = atbash_order;
    new_letter.atbash_rune = atbash_rune;
    new_letter.atbash_value = atbash_value;
    new_letter.atbash_letter_count = atbash_letter_count;
    new_letter.atbash_letter = (char **)malloc(atbash_letter_count * sizeof(char *));
    for (int i = 0; i < atbash_letter_count; i++)
    {
        new_letter.atbash_letter[i] = (char *)malloc(MAX_TRANSLATION_LENGTH * sizeof(char));
        strcpy(new_letter.atbash_letter[i], atbash_letter[i]);
    }
    return new_letter;
}

// Handling the initialization of the gematria alphabet
void init_gematria_alphabet(struct GematriaLetter *gematria_alphabet)
{
    // F
    char letter[1][MAX_TRANSLATION_LENGTH] = {{'F', '\0'}};
    char atbash_letter[1][MAX_TRANSLATION_LENGTH] = {{'E', 'A', '\0'}};
    gematria_alphabet[0] = create_gematria_letter(0, L'ᛠ', 2, 1, letter, 28, L'\u16E0', 109, 1, atbash_letter);

    // U
}

void free_gematria_alphabet(struct GematriaLetter *gematria_alphabet)
{
    if (gematria_alphabet == NULL)
        return;

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
