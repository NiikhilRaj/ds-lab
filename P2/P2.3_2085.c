#include<stdio.h>
#include<stdlib.h>

void traverse(int *arr, int n);
void insert(int *arr, int n);
void delete(int *arr, int n);
void merge(int *arr, int n);

int main()
{
    int n, prompt;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    

    do
    {
        printf("1. Traverse \n2. Insert \n3. Delete \n4. Merge \n5.Exit \n Enter choice: ");
    scanf("%d", &prompt);
         if (prompt==1)
        {
            traverse(arr, n);
            
        }else if (prompt==2)
        {
            insert(arr, n);
        }else if (prompt==3)
        {
            delete(arr, n);
        }else if (prompt==4)
        {
            merge(arr, n);
        }
        
    } while (prompt!=5);
    
       

    return 0;
}


void traverse(int *arr, int n){
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
};

void insert(int *arr, int n){

    int ins, pos;

    printf("Enter the element to insert and its index: ");
    scanf("%d %d", &ins, &pos);

    arr = (int *)realloc(arr, (n+1)*sizeof(int));

    for (int i = n; i >pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=ins;

    traverse(arr, n+1);

};

void delete(int *arr, int n){

    int del;

    printf("Enter the index to be deleted: ");
    scanf("%d", &del);

    for (int i = del; i < n; i++)
    {
        arr[i]=arr[i+1];
    }
    arr=(int *)realloc(arr, (n-1)*sizeof(int));

    traverse(arr, n);
};

void merge(int *arr, int n){
    int s;

    printf("Enter size of array to be merged: ");
    scanf("%d",&s);

    int *arrM=(int *)malloc(s*sizeof(int));

    printf("Enter the numbers: ");

    for (int i = 0; i < s; i++)
    {
        scanf("%d", &arrM[i]);
    }
    arr = (int *)realloc(arr, (n+s)*sizeof(int));

    for (int i = n, j=0;i <(n+s) ; i++, j++)
    {
        arr[i]=arrM[j];
    }
    
    
    for (int i = 0; i < (n+s); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
};