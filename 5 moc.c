#include <stdio.h>

int main() {
    unsigned int a;
    int i, j;

    printf("Enter the number (a): ");
    scanf("%u", &a);

    printf("Enter the index i: ");
    scanf("%d", &i);
    printf("Enter the index j: ");
    scanf("%d", &j);

    if (i < 0 || j < 0 || i > 31 || j > 31) {
        printf("The indexes must be in the range from 0 to 31.\n");
        return 1;
    }

    unsigned int bit_i = (a >> i) & 1;
    unsigned int bit_j = (a >> j) & 1;

    if (bit_i != bit_j) {
        unsigned int mask = (1 << i) | (1 << j);

        a ^= mask;
    }

    printf("The result after the bit exchange: %u\n", a);

    return 0;
}
