
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "salsa20.h"

int main(void) {
    //  demo
    const uint8_t key[32] = {0};
    const uint8_t nonce[8] = {0};
    // Thong diep ban dau
    const uint8_t plaintext[] = "HELLO SALSA20";
    const size_t length = sizeof(plaintext) - 1;
    uint8_t ciphertext[sizeof(plaintext) - 1];
    uint8_t decrypted[sizeof(plaintext)];

    // Ma hoa
    salsa20_12_crypt(
        plaintext, ciphertext, length, key, nonce
    );

    // Giai ma bang cung Key va Nonce
    salsa20_12_crypt(
        ciphertext, decrypted, length, key, nonce
    );

    decrypted[length] = '\0';

    printf("Plaintext: %s\n", (const char *)plaintext);

    printf("Ciphertext (hex): ");
    for (size_t i = 0; i < length; i++) {
        printf("%02X", (unsigned)ciphertext[i]);
    }

    printf("\nDecrypted: %s\n", (const char *)decrypted);

    // Kiem tra ket qua giai ma
    if (memcmp(plaintext, decrypted, length) == 0) {
        printf("Check: PASS\n");
    } else {
        printf("Check: FAIL\n");
    }

    return 0;
}
