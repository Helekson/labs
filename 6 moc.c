#include <stdio.h>

int main() {
    unsigned int a;
    int k;

    printf("Enter the number (a): ");
    scanf("%u", &a);

    printf("Enter the number of low-order bits (k): ");
    scanf("%d", &k);

    if (k < 0 || k > 31) {
        printf("The number of bits must be in the range from 0 to 31.\n");
        return 1;
    }

    unsigned int mask = ~((1U << k) - 1);

    a &= mask;

    printf("The result after zeroing the lower %d bits: %u\n", k, a);

    return 0;
}
