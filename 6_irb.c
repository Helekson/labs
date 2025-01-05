#include <stdio.h>
#include <stdlib.h>


double det_sec_matrix(double **matrix) {
    double a = matrix[0][0];
    double b = matrix[0][1];
    double c = matrix[1][0];
    double d = matrix[1][1];

    double det = a * d - b * c;

    return det;
}

void swap(double **matrix, int i, int j, int n) {
    for (int k = 0; k < n; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

double det_gauss(double **matrix, int n) {
    double det = 1;
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            int swap_found = 0;
            for (int j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    swap(matrix, i, j, n);
                    det = -det;
                    swap_found = 1;
                    break;
                }
            }
            if (!swap_found) {
                return 0;
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (matrix[j][i] != 0) {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = i; k < n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }

        det *= matrix[i][i];
    }

    return det;
}

double dimension_matrix(double **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return det_sec_matrix(matrix);
    } else {
        return det_gauss(matrix, n);
    }
}

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


int main() {
    int n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    double **matrix = malloc(n * sizeof(double *));
    if (matrix == NULL) {
        printf("Error: memory allocation failed for rows!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Error: memory allocation failed for columns in row %d!\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double det = dimension_matrix(matrix, n);
    printf("The determinant of the matrix is: %.2lf\n", det);

    free_matrix(matrix, n);


    return 0;
}
