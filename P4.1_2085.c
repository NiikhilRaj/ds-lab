#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *start = NULL;

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
    int choice, item, index;
    char yn;

    printf("Choose an option: \n1.Create a node \n2.Display the list \n3.Insert element at the beginning \n4.Insert and element at the end \n5.Insert an element at a specific position \n6.Delete the element from the beginnig \n7.Delete an element at the end \n8.Delete an element at a specific position \n9.Count the total number of nodes \n10. Search element from a linked list \n11.Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter your data: ");
    scanf("%d", &item);
    printf("Do you want to continue:(y/n): ");
    scanf("%c", &yn);

    if (yn == 'n' || yn == 'N')
    {
        return;
    }

    switch (choice)
    {
    case 1:
        createNode(start, item);
        break;
    case 2:
        displayList(start);
        break;
    case 3:
        printf("Enter the data to insert at the beginning: ");
        scanf("%d", &item);
        insertBeginning(start, item);
        break;
    case 4:
        printf("Enter the data to insert at the beginning: ");
        scanf("%d", &item);
        insertEnd(start, item);
        break;
    case 5:
        printf("Enter data to insert at a specific position: ");
        scanf("%d", &item);
        printf("Enter the position: ");
        scanf("%d", &index);
        insertSpecific(start, item, index);
        break;
    case 6:
        deleteBegin(start);
        break;
    case 7:
        deleteEnd(start);
        break;
    case 8:
        printf("Enter the position to delete: ");
        scanf("%d", &index);
        deleteSpecific(start, index);
        break;
    case 9:
        countNodes(start);
        break;
    case 10:
        printf("Enter the element to search: ");
        scanf("%d", &item);
        search(start, item);
        break;
    case 11:
        printf("Exiting...\n");
        break;

    default:
        printf("Invalid option");
    }
}

void createNode(NODE *start, int d)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = d;
    newNode->next;
    start = newNode;
};
void displayList(NODE *start)
{
    NODE *temp = start;
    if (temp == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
};
void insertBeginning(NODE *start, int d)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = d;
    if (start == NULL)
    {
        ptr->next = NULL;
        start = ptr;
    }
};
void insertEnd(NODE *start, int d)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = d;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        NODE *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
};
void insertSpecific(NODE *start, int d, int i)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = d;
    if (start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else
    {
        NODE *temp = start;
        for (int j = 0; j < i - 1; j++)
        {
            temp = temp->next;
            ptr->next = temp->next;
            temp->next=ptr;
        }
    }
};
void deleteBegin(NODE *start) {
    if (start==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else
    {
        NODE *temp=start;
        start=start->next;
        printf("%d", temp->data);
        free(temp);
    }
    
};
void deleteEnd(NODE *start) {
    NODE *temp=start, *temp1;
    if (start==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if (start->next==NULL)
    {
        start=NULL;
        printf("%d", temp->data);
        free(temp);
    }
    else
    {
        while (temp->next->next!=NULL)
        {
            temp1=temp->next;
            temp=temp->next;
            temp->next=NULL;
            printf("%d", temp->data);
            free(temp1);
        }
        
    }
    
};
void deleteSpecific(NODE *start, int i) {
    NODE *temp=start, *temp1;
    if (start==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if (start->next==NULL)
    {
        start=NULL;
        printf("%d", temp->data);
        free(temp);
    }
    else
    {
        for (int j = 0; j < i;j++)
        {
            temp1=temp->next;
            if (i=i)
            {
                temp->next=temp1->next;
                printf("%d", temp1->data);
            }
            
        }
        
    }
    
};
void countNodes(NODE *start) {
    NODE *temp=start;
    int count=0;
    if (temp==NULL)
    {
        printf("No elements");
    }
    else
    {
        while (temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        } 
    }
};
void search(NODE *start, int s) {
    NODE *temp=start;
    while (temp!=NULL)
    {
        if (temp->data==s)
        {
            printf("Found");
            return;
        } 
    }
    printf("Not Found");
};