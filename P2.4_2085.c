#include<stdio.h>

int sumRow(int *arr, int r);
int sumCol(int *arr, int c);
int AvgRow(int *arr, int r);
int AvgCol(int *arr, int c);
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
    
    printf("");

    for (int i = 0; i < n; i++)
    {
        
    }
    

}

int sumRow(int a[], int l)
{
    int sum;
    return sum;
};

int sumCol(int a[], int l)
{
    int sum;
    return sum;
};

int AvgRow(int a[], int l)
{
    int sum, avg;
    return avg;
};

int AvgCol(int a[], int l)
{
    int sum, avg;
    return avg;
};

int nonZero(int *arr, int n)
{

};