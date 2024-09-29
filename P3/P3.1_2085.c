#include<stdio.h>

int nonZero(int row, int col, int m[row][col]);
void transpose(int count, int matrixT[count + 1][3]);

void main()
{
    int row, col;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    printf("Enter the elements:");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        
    }
    
    int count = nonZero(row, col, matrix);


    int matrixT[count+1][3], k=0;

    matrixT[0][0]=row;
    matrixT[0][1]=col;
    matrixT[0][2]=count;

    for (int i = 0; i < row; i++)
    {
        for (int  j = 0; j < col; j++)
        {
            if (matrix[i][j]!=0)
            {
                matrixT[k][0]= i;
                matrixT[k][1]= j;
                matrixT[k][2]= matrix[i][j];
                k++;
            }
        }
    }
    
    transpose(count, matrixT);
}

int nonZero(int row, int col, int m[row][col]){
    
    int c=0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j]!=0)
            {
                c++;
            }
            
        }
        
    }

    return c;
};

void transpose(int count, int matrixT[count + 1][3]) {
    printf("\nTranspose of Sparse Matrix:\n");

    for (int i = 1; i <= count; i++) {
        int temp = matrixT[i][0];
        matrixT[i][0] = matrixT[i][1];
        matrixT[i][1] = temp;
    }

    for (int i = 0; i <= count; i++) {
        printf("%d %d %d\n", matrixT[i][0], matrixT[i][1], matrixT[i][2]);
    }
}

