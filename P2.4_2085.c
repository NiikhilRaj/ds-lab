#include<stdio.h>

int sumRow(int *arr, int r, int n);
int sumCol(int *arr, int c, int n);
float AvgRow(int *arr, int r, int n);
float AvgCol(int *arr, int c, int n);
int nonZero(int *arr, int n);

void main()
{
    int n;

    printf("Enter the value of nXn matrix: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter sthe elements of the array: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        
    }
    
    printf("The no of non zero elements are: %d\n", nonZero((int *)arr, n));

    for (int i = 0; i < n; i++)
    {
        printf("Row %d, Sum= %d, Average= %f\n", i+1,sumRow((int *)arr, i, n), AvgRow((int *)arr, i, n));
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Column %d, Sum= %d, Average= %f\n", i+1,sumCol((int *)arr, i, n), AvgCol((int *)arr, i, n));
    }

}

int sumRow(int *arr, int r, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= *((arr + r* n)+ i);
    }
    return sum;
};

int sumCol(int *arr, int c, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= *((arr + i* n)+ c);
    }
    return sum;
};

float AvgRow(int *arr, int r, int n)
{
    return (float)sumRow(arr, r, n)/n;
};

float AvgCol(int *arr, int c, int n)
{
    return (float)sumCol(arr, c, n)/n;
};

int nonZero(int *arr, int n)
{
    int count=0;
    for (int i = 0; i < n * n; i++)
    {
        if (*(arr+i)!=0) count++;
    }
    return count;
};