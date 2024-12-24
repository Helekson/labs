#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {

    int arr[SIZE];
    int max_val, min_val;
    int max_ind, min_ind;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 20001 - 10000;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    max_val = min_val = arr[0];
    max_ind = min_ind = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_ind = i;
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_ind = i;
        }
    }

    printf("\nMaximum value: %d at index %d\n", max_val, max_ind);
    printf("Minimum value: %d at index %d\n", min_val, min_ind);

    return 0;
}

