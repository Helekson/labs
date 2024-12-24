#include <stdio.h>
#include <math.h>
#define N 3

float determinant(float matrix[N][N], int size) {
    float det = 0;
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    float submatrix[N][N];
    for (int x = 0; x < size; x++) {
        int subi = 0;
        for (int i = 1; i < size; i++) {
            int subj = 0;
            for (int j = 0; j < size; j++) {
                if (j == x) continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, size - 1);
    }
    return det;
}

void cofactor(float matrix[N][N], float cofactors[N][N], int size) {
    float submatrix[N][N];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int subi = 0;
            for (int x = 0; x < size; x++) {
                if (x == i) continue;
                int subj = 0;
                for (int y = 0; y < size; y++) {
                    if (y == j) continue;
                    submatrix[subi][subj] = matrix[x][y];
                    subj++;
                }
                subi++;
            }
            cofactors[i][j] = determinant(submatrix, size - 1) * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }
}

void transpose(float matrix[N][N], float result[N][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int inverseMatrix(float matrix[N][N], float inverse[N][N]) {
    float det = determinant(matrix, N);
    if (fabs(det) < 1e-6) {
        printf("\nMatrix is degenerate there is no inverse.\n");
        return 0;
    }

    float cofactors[N][N];
    cofactor(matrix, cofactors, N);

    float adjugate[N][N];
    transpose(cofactors, adjugate, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inverse[i][j] = adjugate[i][j] / det;
        }
    }

    return 1;
}

void printMatrix(float matrix[N][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matrix[N][N] = {
            {2, -1, 0},
            {1,  1, 1},
            {1,  2, 3}
    };

    printf("Original matrix:\n");
    printMatrix(matrix, N);

    float inverse[N][N];
    if (inverseMatrix(matrix, inverse)) {
        printf("\nInverse matrix:\n");
        printMatrix(inverse, N);
    }

    return 0;
}