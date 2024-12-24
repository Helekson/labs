#include <stdio.h>

void transpon(int matrix1[5][5], int matrix2[5][5]) {

    int tempI, tempJ;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix2[j][i] = matrix1[i][j];
        }
    }
}

int main() {

    int matrix1[5][5] = {{1, 2, 3, 4, 5},
                         {6, 7, 8, 9, 10},
                         {11, 12, 13, 14, 15},
                         {16, 17, 18,19, 20},
                         {21, 22, 23, 24, 25}};

    int matrix2[5][5];

    transpon(matrix1, matrix2);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;
}