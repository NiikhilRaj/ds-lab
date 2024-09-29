#include<stdio.h>
#include<stdlib.h>

void compare(int*a, int *b);

void main()
{
    int n1, n2;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    compare(&n1, &n2);
}

void compare(int *a, int*b)
{
    if (*a>*b)        printf("%d is greater than %d\n",*a, *b);
    else if (*b>*a)    printf("%d is greater than %d\n",*b, *a);
    else if (*a==*b)    printf("%d and %d are equal\n", *a, *b);
}