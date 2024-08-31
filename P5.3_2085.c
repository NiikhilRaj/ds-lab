#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int row;
    int col;
    int data;
    struct node *next;
} NODE;

NODE* createNode(int row, int col, int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->row = row;
    newNode->col = col;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

NODE* createSparseMatrix(int rows, int cols, int matrix[rows][cols]) {
    NODE *head = createNode(rows, cols, 0); 
    NODE *current = head;

    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                NODE *newNode = createNode(i, j, matrix[i][j]);
                current->next = newNode;
                current = newNode;
                nonZeroCount++;
            }
        }
    }
    head->data = nonZeroCount;  

    return head;
}

void displaySparseMatrix(NODE *head) {
    if (head == NULL || head->next == NULL) {
        printf("The matrix is empty or has no non-zero elements.\n");
        return;
    }

    NODE *current = head;
    printf("Sparse Matrix Representation (row, col, value):\n");
    while (current != NULL) {
        printf("(%d, %d, %d)\n", current->row, current->col, current->data);
        current = current->next;
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    NODE *sparseMatrix = createSparseMatrix(rows, cols, matrix);

    displaySparseMatrix(sparseMatrix);

    return 0;
}
