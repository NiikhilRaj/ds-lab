#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct que{
    int data[MAX];
    int front, rear;
}QUE;

int isEmpty(QUE*q);
int isFull(QUE *q);
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
    return q->front==-1;
};

int isFull(QUE *q){
    return(q->front==(q->rear+1)%MAX);
};

void create(QUE *q){
    q->front=q->rear=-1;
};

void insert(QUE *q, int item){

    if (isFull(q))
    {
        printf("Overflow\n");
        return;
    }
    if (q->front==-1)
    {
        q->front=q->rear=0;
    }
    else{
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=item;
    }
};

void delete(QUE *q){
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return;
    }
    int dItem=q->data[q->front];
    if (q->front==q->rear) q->front=q->rear=-1;
    else q->front=(q->front+1)%MAX;
    printf("%d", dItem);    
};

void display(QUE *q){
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    
    int i = q->front;
    while (i != q->rear) {
        printf("%d-->", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d-->\n", q->data[q->rear]);

};
