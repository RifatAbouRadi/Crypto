#include "vigenere.h"
#include <string.h>

/* Helper: turn a key character (A–Z) into its shift value (A=0, B=1, ... Z=25). */
static int key_shift(char k) {
    return k - 'A';
}

char *vigenere_encrypt(char *plaintext, char *key) {
    size_t key_len = strlen(key);
    size_t j = 0;

    for (char *p = plaintext; *p; ++p) {
        if (*p >= 'A' && *p <= 'Z') {
            int shift = key_shift(key[j % key_len]);
            *p = (char)('A' + ((*p - 'A' + shift) % 26));
            j++;
        }
    }
    return plaintext;
}

char *vigenere_decrypt(char *ciphertext, char *key) {
    size_t key_len = strlen(key);
    size_t j = 0;

    for (char *p = ciphertext; *p; ++p) {
        if (*p >= 'A' && *p <= 'Z') {
            int shift = key_shift(key[j % key_len]);
            *p = (char)('A' + ((*p - 'A' - shift + 26) % 26));
            j++;
        }
    }
    return ciphertext;
}
