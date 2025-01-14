#include <stdio.h>

unsigned int combineEdges(unsigned int num, int len, int i) {
    unsigned int firstBits = (num >> (len - i)) & ((1 << i) - 1);

    unsigned int lastBits = num & ((1 << i) - 1);

    return (firstBits << i) | lastBits;
}

unsigned int extractMiddleBits(unsigned int num, int len, int i) {
    unsigned int middleBits = num >> i;

    return middleBits & ((1 << (len - 2 * i)) - 1);
}

int main() {
    unsigned int num = 0b100011101101;
    int len = 12;
    int i = 3;

    unsigned int combined = combineEdges(num, len, i);
    printf("Combined edges: 0b");
    for (int j = len - i * 2 - 1; j >= 0; j--) {
        printf("%d", (combined >> j) & 1);
    }
    printf("\n");
    
    unsigned int middle = extractMiddleBits(num, len, i);
    printf("Middle bits: 0b");
    for (int j = len - 2 * i - 1; j >= 0; j--) {
        printf("%d", (middle >> j) & 1);
    }
    printf("\n");

    return 0;
}
