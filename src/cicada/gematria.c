#include "stdlib.h"

/*
    GEMATRIA PRIMUS
*/

struct GematriaLetter
{
    int order;           // rune order
    char *letter;        // english translation
    int letter_len;      // english letter lenght(could be either 1 or 2)
    char rune;           // rune
    int value;           // numerical value of the letter
    int atbash_value;    // atbash value of the letter decimal[i] = 28 - decimal[i]
    char atbash_rune;    // atbash rune of the letter
    char *atbash_letter; // atbash translation
    int atbash_len;      // atbash letter length(could be either 1 or 2)
    int atbash_order;    // atbash order of the letter
};

// constructor for the struct
struct GematriaLetter *new_GematriaLetter(int order, const char *letter, char rune, 
int value, int atbash_value, char atbash_rune, const char *atbash_letter, int atbash_order)
{
    struct GematriaLetter *res = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter));
    res->order = order;
    res->letter_len = strlen(letter);
    res->letter = (char *)malloc(res->letter_len + 1);
    strcpy(res->letter, letter);
    res->rune = rune;
    res->value = value;
    res->atbash_value = atbash_value;
    res->atbash_rune = atbash_rune;
    res->atbash_len = strlen(atbash_letter);
    res->atbash_letter = (char *)malloc(res->atbash_len + 1);
    strcpy(res->atbash_letter, atbash_letter);
    res->atbash_order = atbash_order;
    return res;
}

// Building Gematria
struct GematriaLetter *gemAlphabet /*= (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 29);*/;

void init_gematria_alphabet()
{
    // initialize the alphabet
    gemAlphabet = (struct GematriaLetter *)malloc(sizeof(struct GematriaLetter) * 32); // 29

    /*
        "ᚠ", "ᚢ", "ᚦ", "ᚩ", "ᚱ", "ᚳ", "ᚷ", "ᚹ", "ᚻ", "ᚾ", "ᛁ", "ᛂ", "ᛇ", "ᛈ", "ᛉ", "ᛋ", "ᛏ",
        "ᛒ", "ᛖ", "ᛗ", "ᛚ", "ᛝ", "ᛟ", "ᛞ", "ᚪ", "ᚫ", "ᚣ", "ᛡ", "ᛠ"
    */
    // fill the alphabet
    struct GematriaLetter *F = new_GematriaLetter(0, 'F', 'ᚠ', 2, 109, 'ᛠ', 'EA', 20);
    struct GematriaLetter *U = new_GematriaLetter(1, 'U', 'ᚢ', 3, 107, 'ᛡ', 'IA', 20);
    struct GematriaLetter *TH = new_GematriaLetter(2, 'TH', 'ᚦ', 5, 103, 'ᚣ', 'Y', 20);
    struct GematriaLetter *O = new_GematriaLetter(3, 'O', 'ᚩ', 7, 101, 'ᚫ', 'AE', 20);
    struct GematriaLetter *R = new_GematriaLetter(4, 'R', 'ᚱ', 11, 97, 'ᚪ', 'A', 20);
    struct GematriaLetter *C = new_GematriaLetter(5, 'C', 'ᚳ', 13, 89, 'ᛞ', 'D', 20);
    struct GematriaLetter *K = new_GematriaLetter(5, 'K', 'ᚳ', 13, 89, 'ᛞ', 'D', 20);
    struct GematriaLetter *G = new_GematriaLetter(6, 'G', 'ᚷ', 17, 83, 'ᛟ', 'OE', 20);
    struct GematriaLetter *W = new_GematriaLetter(7, 'W', 'ᚹ', 19, 79, 'ᛝ', 'NG', 20);
    struct GematriaLetter *H = new_GematriaLetter(8, 'H', 'ᚻ', 23, 73, 'ᛚ', 'L', 20);
    struct GematriaLetter *N = new_GematriaLetter(9, 'N', 'ᚾ', 29, 71, 'ᛗ', 'M', 20);
    struct GematriaLetter *I = new_GematriaLetter(10, 'I', 'ᛁ', 31, 67, 'ᛖ', 'E', 20);
    struct GematriaLetter *J = new_GematriaLetter(11, 'J', 'ᛂ', 37, 61, 'ᛒ', 'B', 20);
    struct GematriaLetter *EO = new_GematriaLetter(12, 'EO', 'ᛇ', 41, 59, 'ᛏ', 'T', 20);
    struct GematriaLetter *P = new_GematriaLetter(13, 'P', 'ᛈ', 43, 53, 'ᛋ', 'S', 20);
    struct GematriaLetter *X = new_GematriaLetter(14, 'X', 'ᛉ', 47, 47, 'ᛉ', 'X', 20);
    struct GematriaLetter *S = new_GematriaLetter(15, 'S', 'ᛋ', 53, 43, 'ᛈ', 'P', 20);
    struct GematriaLetter *Z = new_GematriaLetter(15, 'Z', 'ᛋ', 53, 43, 'ᛈ', 'P', 20);
    struct GematriaLetter *T = new_GematriaLetter(16, 'T', 'ᛏ', 59, 41, 'ᛇ', 'EO', 20);
    struct GematriaLetter *B = new_GematriaLetter(17, 'B', 'ᛒ', 61, 37, 'ᛂ', 'J', 20);
    struct GematriaLetter *E = new_GematriaLetter(18, 'E', 'ᛖ', 67, 31, 'ᛁ', 'I', 20);
    struct GematriaLetter *M = new_GematriaLetter(19, 'M', 'ᛗ', 71, 29, 'ᚾ', 'N', 20);
    struct GematriaLetter *L = new_GematriaLetter(20, 'L', 'ᛚ', 73, 23, 'ᚻ', 'H', 20);
    struct GematriaLetter *NG = new_GematriaLetter(21, 'NG', 'ᛝ', 79, 19, 'ᚹ', 'W', 20);
    struct GematriaLetter *ING = new_GematriaLetter(21, 'ING', 'ᛝ', 79, 19, 'ᚹ', 'W', 20);
    struct GematriaLetter *OE = new_GematriaLetter(22, 'OE', 'ᛟ', 83, 17, 'ᚷ', 'G', 20);
    struct GematriaLetter *D = new_GematriaLetter(23, 'D', 'ᛞ', 89, 13, 'ᚳ', 'C', 20);
    struct GematriaLetter *A = new_GematriaLetter(24, 'A', 'ᚪ', 97, 11, 'ᚱ', 'R', 20);
    struct GematriaLetter *AE = new_GematriaLetter(25, 'AE', 'ᚫ', 101, 7, 'ᚩ', 'O', 20);
    struct GematriaLetter *Y = new_GematriaLetter(26, 'Y', 'ᚣ', 103, 5, 'ᚦ', 'TH', 20);
    struct GematriaLetter *IA = new_GematriaLetter(27, 'IA', 'ᛡ', 107, 3, 'ᚢ', 'U', 20);
    struct GematriaLetter *IO = new_GematriaLetter(27, 'IO', 'ᛡ', 107, 3, 'ᚢ', 'U', 20);
    struct GematriaLetter *EA = new_GematriaLetter(28, 'EA', 'ᛠ', 109, 2, 'ᚠ', 'F', 20);

    gemAlphabet[0] = *F;
}
