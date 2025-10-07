#include "caesar.h"

/* Each letter is shifted by 3 (A→D, B→E, …, X→A, Y→B, Z→C)
   Only uppercase letters (A–Z) are processed.
   The function edits the text in place and returns the same pointer.
*/

static char shift_encrypt(char c) {
    if (c >= 'A' && c <= 'Z')
        return (char)('A' + (c - 'A' + 3) % 26);
    return c;
}

static char shift_decrypt(char c) {
    if (c >= 'A' && c <= 'Z')
        return (char)('A' + (c - 'A' - 3 + 26) % 26);
    return c;
}

char *caesar_encrypt(char *plaintext) {
    for (char *p = plaintext; *p; ++p)
        *p = shift_encrypt(*p);
    return plaintext;
}

char *caesar_decrypt(char *ciphertext) {
    for (char *p = ciphertext; *p; ++p)
        *p = shift_decrypt(*p);
    return ciphertext;
}
