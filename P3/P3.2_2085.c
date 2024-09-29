#include <stdio.h>

void addSparseMatrices(int matrixA[][3], int matrixB[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;

    result[0][0] = matrixA[0][0];
    result[0][1] = matrixA[0][1];
    result[0][2] = 0;

    while (i <= matrixA[0][2] && j <= matrixB[0][2]) {
        if (matrixA[i][0] < matrixB[j][0] || 
            (matrixA[i][0] == matrixB[j][0] && matrixA[i][1] < matrixB[j][1])) {
            result[k][0] = matrixA[i][0];
            result[k][1] = matrixA[i][1];
            result[k][2] = matrixA[i][2];
            i++;
        } 
        else if (matrixB[j][0] < matrixA[i][0] || 
            (matrixB[j][0] == matrixA[i][0] && matrixB[j][1] < matrixA[i][1])) {
            result[k][0] = matrixB[j][0];
            result[k][1] = matrixB[j][1];
            result[k][2] = matrixB[j][2];
            j++;
        } 
        else {
            result[k][0] = matrixA[i][0];
            result[k][1] = matrixA[i][1];
            result[k][2] = matrixA[i][2] + matrixB[j][2];
            i++;
            j++;
        }
        k++;
        result[0][2]++;
    }

    while (i <= matrixA[0][2]) {
        result[k][0] = matrixA[i][0];
        result[k][1] = matrixA[i][1];
        result[k][2] = matrixA[i][2];
        i++;
        k++;
        result[0][2]++;
    }

    while (j <= matrixB[0][2]) {
        result[k][0] = matrixB[j][0];
        result[k][1] = matrixB[j][1];
        result[k][2] = matrixB[j][2];
        j++;
        k++;
        result[0][2]++;
    }
}

void inputSparseMatrix(int matrix[][3], int nonZero) {
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix[0][0], &matrix[0][1]);

    matrix[0][2] = nonZero;

    printf("Enter the row index, column index, and non-zero value:\n");
    for (int i = 1; i <= nonZero; i++) {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }
}

void printSparseMatrix(int matrix[][3]) {
    printf("Sparse Matrix (3-tuple format):\n");
    printf("Row Col Value\n");
    for (int i = 0; i <= matrix[0][2]; i++) {
        printf("%d    %d    %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    int nonZeroA, nonZeroB;

    printf("Enter the number of non-zero elements in matrix A: ");
    scanf("%d", &nonZeroA);
    printf("Enter the number of non-zero elements in matrix B: ");
    scanf("%d", &nonZeroB);

    int matrixA[nonZeroA + 1][3], matrixB[nonZeroB + 1][3];
    int result[nonZeroA + nonZeroB + 1][3];

    printf("\nMatrix A:\n");
    inputSparseMatrix(matrixA, nonZeroA);

    printf("\nMatrix B:\n");
    inputSparseMatrix(matrixB, nonZeroB);

    addSparseMatrices(matrixA, matrixB, result);

    printf("\nResultant Matrix (A + B):\n");
    printSparseMatrix(result);

    return 0;
}
