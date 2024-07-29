#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n, search;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (search==arr[i])   
        {
            printf("%d is at index %d\n", search, i);
        }
        
    }
    
}