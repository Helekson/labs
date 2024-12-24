#include <stdio.h>

#define SIZE 10

int main() {

    int arr[SIZE];
    int oddArr[SIZE];
    int count = 0;

    printf("Enter %d element to the arr:\n", SIZE);
    printf("Arr:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < SIZE; i++ ) {
        printf("Arr[%d] = %d\n", i, arr[i]);
    }

    for (int i = 1; i < SIZE; i += 2) {
        oddArr[count] = arr[i];
        count++;
    }

    printf("\nOddArr:\n");
    for (int i = 0; i < count; i++) {
        printf("OddArr[%d] = %d\n", i, oddArr[i]);
    }

    return 0;
}
