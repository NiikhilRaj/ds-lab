#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *start = NULL;

NODE *createNode(int data);
NODE *createList(int n);
void displayList(NODE *start);

int main()
{
    int n;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    start= createList(n);
    if (start!=NULL)
    {
        displayList(start);
    }
    
    return 0;
}

NODE *createNode(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

NODE *createList(int n)
{
    NODE *newNode, *temp;
    int data;

    if (n == 0)
    {
        return NULL;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data of node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);

        if (start == NULL)
        {
            start = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        
        
    }

    if (temp!=NULL)
    {
        temp->next = start;
    }
    

    return start;
};
void displayList(NODE *start)
{
    NODE *temp = start;
    if (start == NULL)
    {
        printf("Empty list");
        return;
    }
    else{
        printf("circular list: ");
        do
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }while (temp != start);
    }
    printf("\n");
};