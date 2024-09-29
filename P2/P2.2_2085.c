#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n,sizeof(int));

    printf("Enter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int large= arr[0];

    for (int i = 0; i < n; i++)
    {
        if (large<arr[i])   
        {
            large=arr[i];
        }
    }

    int *hash= (int*)calloc(large,sizeof(int));
    int temp=0;

    for (int i = 0; i < n; i++)
    {
        temp=arr[i];
        hash[temp]++;    
    }
    
    int count=0;

    for (int i = 0; i <= large; i++)
    {
        if (hash[i]>0)
        {
            count++;
        }
    }
    
    int *arrOut= (int *)malloc(count*sizeof(int));
    int x=0;

    for (int i = 0; i <= large; i++)
    {
        if (hash[i]>0)
        {
            arrOut[x]=i;
            x++;
        }
    }
    
    printf("Array with distinct elements: ");

    for (int i = 0; i <= count ; i++)
    {
        printf("%d ", arrOut[i]);
    }
    printf("\n");

    return 0;
}