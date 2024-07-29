#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char name[100], author[100], publication[100];
    int price;
};

struct book* add();
void printBook(char author[100], struct book *bookList[], int size) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(bookList[i]->author, author) == 0) {
            printf("Book: %s, Author: %s, Publication: %s, Price: %d\n",
                   bookList[i]->name, bookList[i]->author, bookList[i]->publication, bookList[i]->price);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by the author %s\n", author);
    }
}


void main()
{
    int bookNo;
    int iteration=0;
    int action;

    printf("Enter no of books: ");
    scanf("%d", &bookNo);

    struct book *book[bookNo];

    do
    {
        printf("1 to add book\n");
        printf("2 to search author\n ->");
        scanf("%d", &action);
        if (action==1)
        {
            book[iteration]=add();
        }
        else if (action==2)
        {  
            char search[100];
            printf("Enter the author name: ");
            scanf("%s", search);

            printBook(search, book, sizeof(book)/sizeof(book[0]));
        }
        iteration++;       
        printf("\n"); 
    } while (iteration<=bookNo);    
}

struct book* add(){
    struct book *book = (struct book*)malloc(sizeof(struct book));

    char bookName[100], bookAuthor[100], pub[100];
    int bookPrice;

    printf("Book name: ");
    scanf("%s", bookName);

    printf("Author name: ");
    scanf("%s", bookAuthor);

    printf("Publication: ");
    scanf("%s", pub);

    printf("Price: ");
    scanf("%d", &bookPrice);

    book->price= bookPrice;
    strcpy(book->name, bookName);
    strcpy(book->author, bookAuthor);
    strcpy(book->publication, pub);
    
};

