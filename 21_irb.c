#include <stdio.h>
#include <ctype.h>

int baseToInt(const char *str, int base) {
    if (base < 2 || base > 36) {
        printf("Base must be in the range [2..36].\n");
        return 0;
    }

    int value = 0;
    int isNegative = 0;
    int index = 0;

    if (str[0] == '-') {
        isNegative = 1;
        index = 1;
    }

    for (; str[index] != '\0'; index++) {
        char c = toupper(str[index]);
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            digit = c - 'A' + 10;
        } else {
            printf("Invalid character in input string: %c\n", c);
            return 0;
        }

        if (digit >= base) {
            printf("Invalid digit for base %d: %c\n", base, c);
            return 0;
        }

        value = value * base + digit;
    }

    return isNegative ? -value : value;
}

int main() {
    const char *str = "-1A";
    int base = 16;

    int result = baseToInt(str, base);
    printf("Integer value: %d\n", result);

    return 0;
}
