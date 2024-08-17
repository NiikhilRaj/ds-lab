#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *start=NULL;

void createNode(NODE *start, int d);
void displayList(NODE *start);
void insertBeginning(NODE *start, int d);
void insertEnd(NODE *start, int d);
void insertSpecific(NODE *start, int d, int i);
void deleteBegin(NODE *start);
void deleteEnd(NODE *start);
void deleteSpecific(NODE *start, int i);
void countNodes(NODE *start);
void search(NODE *start, int s);


void main()
{
    int choice, item;
    char yn;    

    printf("Choose an option: \n1.Create a node \n2.Display the list \n3.Insert element at the beginning \n4.Insert and element at the end \n5.Insert an element at a specific position \n6.Delete the element from the beginnig \n7.Delete an element at the end \n8.Delete an element at a specific position \n9.Count the total number of nodes \n10. Search element from a linked list \n11.Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter your data: ");
    scanf("%d",&item);
    printf("Do you want to continue:(y/n): ");
    scanf("%c", &yn);

    if (yn =='n')        
    {
        return;
    }

    switch (choice)
    {
    case 1:
        NODE n1;         
        break;
    case 2:
        displayList(&n1);
        break;
    case 3:
        printf("Enter the data to insert at the beginning: ");
        scanf("%d", &item);
        insertBeginning(&n1, item);
        break;
    case 4:
        insertEnd(&n1, item);
        break;
    case 5:
        int index;
        insertSpecific(&n1, item, index);
        break;
    case 6:
        deleteBegin(&n1);
        break;
    case 7:
        deleteEnd(&n1);
        break;
    case 8:
        deleteSpecific(&n1, index);
        break;
    case 9:
        countNodes(&n1);
        break;
    case 10:
        int srh;
        search(&n1,srh);
        break;
    case 11:
        break;
    
    default:
        printf("Invalid option");
    }
    
}