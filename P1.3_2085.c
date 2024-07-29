#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length(char *a);

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("The length of the string is %d\n", length(str));

    return 0;
}

int length(char *a){

    int count=0;

while (*a != '\0')
    {
        count++;
        a++;
    }
    return count;
}