#include <stdio.h>
#include <string.h>

void intToBase(int number, int base, char *result) {
    if (base < 2 || base > 36) {
        printf("Base must be in the range [2..36].\n");
        return;
    }

    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int isNegative = 0;

    if (number < 0 && base == 10) {
        isNegative = 1;
        number = -number;
    }

    char buffer[65];
    int index = 0;

    do {
        buffer[index++] = digits[number % base];
        number /= base;
    } while (number > 0);

    if (isNegative) {
        buffer[index++] = '-';
    }

    buffer[index] = '\0';

    for (int i = 0; i < index; i++) {
        result[i] = buffer[index - i - 1];
    }
    result[index] = '\0';
}

int main() {
    int number = -255;
    int base = 16;
    char result[65];

    intToBase(number, base, result);
    printf("Number in base %d: %s\n", base, result);

    return 0;
}