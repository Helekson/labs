#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

bool contains(double arr[], int size, double value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    double arr[SIZE];
    double uniqueArr[SIZE];
    int uniqueCount = 0;

    printf("Enter %d double values for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &arr[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        if (!contains(uniqueArr, uniqueCount, arr[i])) {
            uniqueArr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    printf("Array with unique values:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%.2lf ", uniqueArr[i]);
    }
    printf("\n");

    return 0;
}
