#include <stdio.h>

int main() {

    int a;
    int k;

    printf("Enter integer:");
    scanf("%d", &a);

    printf("Enter bit number:");
    scanf("%d", &k);

    if (k <  0 || k >= sizeof(int) * 8)  {
        printf("Error", sizeof(int) * 8 - 1);

        return 1;
    }

    a &= ~(1 << k);

    printf("The number after removing the %dth bit: %d\n", k, a);

    return 0;
}