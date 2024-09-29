#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;
typedef struct que{
    NODE *front, *rear;
}QUE;

int isEmpty(QUE*q);
void create(QUE *q);
void insert(QUE *q, int item);
void delete(QUE *q);
void display(QUE *q);

void main()
{
    int choice=0, item;

    QUE *q=(QUE *)malloc(sizeof(QUE));
    create(q);

    while (choice!=4)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert(q, item);
            break;
        case 2:
            delete(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
        printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

int isEmpty(QUE*q){
    return(q->front==NULL);
};

void create(QUE *q){
    q->front=q->rear=NULL;
};

void insert(QUE *q, int item){
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=item;
    temp->next=NULL;
    if (isEmpty(q))
    {
        q->front=q->rear=temp;
        q->rear->next=q->front;
    }
    else
    {
        q->rear->next=temp;
        q->rear=temp;
        q->rear->next=q->front;
    }
    
};

void delete(QUE *q){
    if (isEmpty(q))
    {
        printf("Empty\n");
        return;
    }
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp=q->front;
    if (q->front==q->rear)
    {
        q->front=q->rear=NULL;
    }
    else
    {
        q->front=temp->next;
        q->rear->next=q->front;
    }
    free(temp);
};

void display(QUE *q){
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    NODE *temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d-->", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
};