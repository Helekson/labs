#include <stdio.h>

void swap(int *a, int *b) {

    int q = *a;
    *a = *b;
    *b = q;

}

int main() {
    int c, d;

    printf("Enter first integer: \n");
    scanf("%d", &c);

    printf("Enter second integer: \n");
    scanf("%d", &d);

    printf("Before swap: first = %d, second = %d\n", c, d);

    swap(&c, &d);

    printf("After swap: first = %d, second = %d", c, d);

    return 0;
}
