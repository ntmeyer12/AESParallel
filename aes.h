#ifndef AES_H
#define AES_H

#include <stdint.h>

#include "aesoptions.h"

class AES
{
public:

    AES() {}

    void encrypt(const AESOptions & options);

private:

    void initKey();

    void keyExpansion();

    void addRoundKey(int round, uint8_t state[4][4]);

    static void subBytes(uint8_t state[4][4]);

    static void shiftRows(uint8_t state[4][4]);

    static void mixColumns(uint8_t state[4][4]);

    void cipher(uint8_t *in, uint8_t *out);

    static uint8_t xtime(uint8_t x);

private:

    uint8_t mKey[32];       ///< The key input to the AES Program
    uint8_t mRoundKey[240]; ///< Array of round keys

};

#endif // AES_H
