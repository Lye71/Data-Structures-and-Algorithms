#include <stdio.h>
#include <stdint.h>
#define WORD 32

void wordToBit(uint32_t word, int bit[WORD]) {
    for (int i = 0; i < WORD; i++) {
        bit[WORD - 1 - i] = (word >> i) & 1;
    }
}

uint32_t bitToWord(int bit[WORD]){
    uint32_t word = 0;
    for(int i = 0; i < WORD; i++){
        word = (word << 1) | (bit[i] & 1);
    }
    return word;
}

int main() {
    uint32_t word = 305419896; //(0x12345678)
    int bitVector[WORD];

    wordToBit(word, bitVector);

    printf("Word: %u (0x%X)\n", word, word);
    printf("Bit Vector: ");
    for (int i = 0; i < WORD; i++) {
        printf("%d", bitVector[i]);
    }
    printf("\n");

    uint32_t reconstructedWord = bitToWord(bitVector);
    printf("Reconstructed Word: %u (0x%X)\n", reconstructedWord, reconstructedWord);

    return 0;
}

