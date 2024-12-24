#include <stdio.h>

int arr[5] = {10, 6, 15, 7, 12};
int a, b, c;

int main() {

    for (a = 0; a < 5 - 1; a++) {

        for (b = 0; b < 5 - a - 1; b++) {

            if (arr[b] > arr[b + 1]) {

                c = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = c;
            }
        }
    }
    for (a = 0; a < 5; a++) {
        printf("arr[%d] = %d\n", a, arr[a]);
    }
    return 0;
}