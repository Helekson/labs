#include <stdio.h>

int main() {

    int a;
    int k;

    printf("Enter integer:");
    scanf("%d", &a);

    printf("Enter bit number:");
    scanf("%d", &k);

    if(k < 0 || k >= sizeof(int) * 8) {
        printf("Error\n");

        return 1;
    }
    int bit_value = (a >> k) & 1;

    printf("The value of the %d bitof the number %d is equal to: %d", k, a, bit_value);

    return 0;
}