#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int evenArr[SIZE];
    int count = 0;

    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[count] = arr[i];
            count++;
        }
    }

    if (count > 0) {
        printf("Even numbers:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", evenArr[i]);
        }
        printf("\n");
    } else {
        printf("No even numbers found.\n");
    }

    return 0;
}
