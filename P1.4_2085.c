#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int small=arr[0], large=arr[0];

    for (int i = 0; i < n; i++)
    {
        if (small>arr[i])
        {
            small=arr[i];
        }
        if (large<arr[i])   
        {
            large=arr[i];
        }
    }

    printf("Largest= %d, Smallest= %d\n", large, small);    

    return 0;
}