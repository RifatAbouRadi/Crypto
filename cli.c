#include "cli.h"
#include "caesar.h"
#include "vigenere.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_SZ 4096

/* Print help text (ASCII only) */
static void usage(const char *prog) {
    printf(
        "Usage:\n"
        "  %s MODE ALGORITHM TEXT [KEY]\n\n"
        "Modes:\n"
        "  e, encrypt    Encrypt the input text\n"
        "  d, decrypt    Decrypt the input text\n\n"
        "Algorithms:\n"
        "  c, caesar     Caesar cipher\n"
        "  v, vigenere   Vigenere cipher\n\n"
        "Examples:\n"
        "  %s e c HELLO\n"
        "  %s d v LXFOPVEFRNHR LEMON\n",
        prog, prog, prog
    );
}

/* Copy NUL-terminated string src -> dst */
static void copy_str(char *dst, const char *src) {
    while ((*dst++ = *src++)) { /* loop copies including NUL */ }
}

/* Lowercase first character safely; returns '\0' if s is NULL/empty */
static char first_lower(const char *s) {
    if (!s || !*s) return '\0';
    return (char)tolower((unsigned char)s[0]);
}

int run_cli(int argc, char **argv) {
    if (argc < 4) {
        usage(argv[0]);
        return 1;
    }

    char mode0 = first_lower(argv[1]);   /* 'e' or 'd' */
    char algo0 = first_lower(argv[2]);   /* 'c' or 'v' */
    const char *text = argv[3];

    if (!(mode0 == 'e' || mode0 == 'd')) {
        usage(argv[0]);
        return 1;
    }
    if (!(algo0 == 'c' || algo0 == 'v')) {
        usage(argv[0]);
        return 1;
    }

    char buf[BUF_SZ];
    copy_str(buf, text);   /* operate in-place on local buffer */

    if (algo0 == 'c') {
        if (mode0 == 'e') {
            puts(caesar_encrypt(buf));
        } else {
            puts(caesar_decrypt(buf));
        }
        return 0;
    }

    /* Vigenere path */
    if (argc < 5) {
        fprintf(stderr, "Error: Vigenere requires a KEY (letters A-Z).\n");
        return 2;
    }

    char keybuf[BUF_SZ];
    copy_str(keybuf, argv[4]);

    if (mode0 == 'e') {
        puts(vigenere_encrypt(buf, keybuf));
    } else {
        puts(vigenere_decrypt(buf, keybuf));
    }

    return 0;
}
