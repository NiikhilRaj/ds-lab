#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, count;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n,sizeof(int));

    printf("Enter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }



    return 0;
}