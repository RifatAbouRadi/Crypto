#ifndef caesar.h
#define caesar.h
/** Encrypts plaintext in place using Caesar shift +3 (A→D, …, Z→C).
 *  @param plaintext NUL-terminated uppercase string (A–Z only).
 *  @return The same pointer (plaintext), now encrypted.
 */
char *caesar_encrypt(char *plaintext);

/** Decrypts ciphertext in place using Caesar shift −3 (D→A, …, C→Z).
 *  @param ciphertext NUL-terminated uppercase string (A–Z only).
 *  @return The same pointer (ciphertext), now decrypted.
 */
char *caesar_decrypt(char *ciphertext);

#endif // CAESAR_H

