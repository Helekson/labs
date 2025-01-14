#include <stdio.h>

int max_power_of_two(int num) {
    if (num == 0) {
        return -1;
    }

    int power = 0;

    while ((num & 1) == 0) {
        num >>= 1;
        power++;
    }

    return power;
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    int result = max_power_of_two(number);

    if (result == -1) {
        printf("The number is zero. The degree is not defined.\n");
    } else {
        printf("The maximum power of 2 by which the number is divided %d: %d\n", number, result);
    }

    return 0;
}
