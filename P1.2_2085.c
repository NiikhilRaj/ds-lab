#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char name[100], author[100], publication[100];
    int price;
};

struct book* add()   
{
    struct book *book = (struct book*)malloc(sizeof(struct book));

    char bookName[100], bookAuthor[100], pub[100];
    int bookPrice;

    printf("Book name: ");
    scanf("%s", bookName);

    printf("Author name: ");
    scanf("%s", bookAuthor);

    printf("Publication: ");
    scanf("%s", &pub);

    printf("Price: ");
    scanf("%d", &bookPrice);
};


void main()
{
    int bookNo;
    int iteration;
    int action;

    printf("Enter no of books: ");
    scanf("%d", &bookNo);

    struct book *book[bookNo];

    do
    {
        printf("1 to add book");
        printf("2 to search author\n ->");
        scanf("%d", action);
        if (action==1)
        {
            book[iteration]=add();
        }
        else if (action==2)
        {  
            
        }
        iteration++;        
    } while (iteration<=bookNo);
    
}