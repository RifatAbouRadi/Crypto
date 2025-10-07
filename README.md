# 🔐 Crypto Ciphers — Caesar & Vigenère (C Project)

This project implements two classic substitution ciphers — **Caesar** and **Vigenère** — as a modular C program that can **encrypt** and **decrypt** uppercase text from the command line.

It was developed as part of a programming assignment focusing on **modular design**, **header files**, and **command-line interfaces** in C.

---

## 🧩 Overview

The program supports the following command-line format:

```bash
./crypto MODE ALGORITHM TEXT [KEY]
---

### parameter
| Argument    | Description                                                              |
| ----------- | ------------------------------------------------------------------------ |
| `MODE`      | `e` or `encrypt` for encryption, `d` or `decrypt` for decryption         |
| `ALGORITHM` | `c` or `caesar` for Caesar cipher, `v` or `vigenere` for Vigenère cipher |
| `TEXT`      | Uppercase message to encrypt/decrypt (A–Z only, no spaces)               |
| `[KEY]`     | Only required for Vigenère cipher (e.g. `LEMON`)                         |
