#include <stdio.h>
#include <stdlib.h>

void getMinor(int **matrix, int **minor, int n, int row, int col) {
    int i_minor = 0, j_minor = 0;

    for (int i = 0; i < n; i++) {
        if (i == row) continue;

        j_minor = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) continue;

            minor[i_minor][j_minor] = matrix[i][j];
            j_minor++;
        }
        i_minor++;
    }
}

int determinant(int **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }

    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    int det = 0;
    int sign = 1;
    int **minor = (int **)malloc((n - 1) * sizeof(int *));

    for (int i = 0; i < n - 1; i++) {
        minor[i] = (int *)malloc((n - 1) * sizeof(int));
    }

    for (int col = 0; col < n; col++) {
        getMinor(matrix, minor, n, 0, col);
        det += sign * matrix[0][col] * determinant(minor, n - 1);
        sign = -sign;
    }

    for (int i = 0; i < n - 1; i++) {
        free(minor[i]);
    }
    free(minor);

    return det;
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det = determinant(matrix, n);
    printf("Determinant of the matrix: %d\n", det);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
