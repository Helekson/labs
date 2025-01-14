#include <stdio.h>

#define BITS 32

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (BITS - (n))))

#define ROTATE_RIGHT(x, n) (((x) >> (n)) | ((x) << (BITS - (n))))

int main() {
    unsigned int value = 0x12345678;
    int shift = 4;
    printf("How many bits should the number be shifted by?\n");
    scanf("%d", &shift);

    printf("Original value: 0x%X\n", value);
    printf("After left rotation by %d bits: 0x%X\n", shift, ROTATE_LEFT(value, shift));
    printf("After right rotation by %d bits: 0x%X\n", shift, ROTATE_RIGHT(value, shift));

    return 0;
}