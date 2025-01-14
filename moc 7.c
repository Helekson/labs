#include <stdio.h>

void swap_bytes(unsigned int *num, int order[4]) {
    unsigned char bytes[4];

    for (int i = 0; i < 4; i++) {
        bytes[i] = (*num >> (i * 8)) & 0xFF;
    }

    unsigned int result = 0;
    for (int i = 0; i < 4; i++) {
        result |= (bytes[order[i]] << (i * 8));
    }

    *num = result;
}

int main() {
    unsigned int number;
    int order[4];

    printf("Enter integer: ");
    scanf("%u", &number);

    printf("Enter the byte order:\n");
    for (int i = 0; i < 4; i++) {
        printf("Position %d: ", i);
        scanf("%d", &order[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (order[i] < 0 || order[i] > 3) {
            printf("Error\n");
            return 1;
        }
    }

    swap_bytes(&number, order);
    
    printf("Result: %u\n", number);

    return 0;
}