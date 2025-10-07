#ifndef VIGENERE_H
#define VIGENERE_H

/** Encrypts plaintext (A–Z) in place using Vigenère cipher with given key.
 *  Example: plaintext "ATTACKATDAWN", key "LEMON" → ciphertext "LXFOPVEFRNHR"
 */
char *vigenere_encrypt(char *plaintext, char *key);

/** Decrypts ciphertext (A–Z) in place using Vigenère cipher with given key.
 *  Example: ciphertext "LXFOPVEFRNHR", key "LEMON" → plaintext "ATTACKATDAWN"
 */
char *vigenere_decrypt(char *ciphertext, char *key);

#endif // VIGENERE_H
