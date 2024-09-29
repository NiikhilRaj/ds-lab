#include<stdio.h>
#include<stdlib.h>

typedef struct deque{
    int data;
    struct deque *next;
}dq;
typedef struct DEQUE{
    dq *front;
    dq *rear;
}DQ;

void create(DQ *q);
void insertAtFront(DQ *q, int item);
void insertAtRear(DQ *q, int item);
void deleteFront(DQ *q);
void deleteRear(DQ *q);
void display(DQ *q);

void main()
{
    int choice=0, item;
    DQ *q=(DQ *)maloc(sizeof(DQ));
    create(q);
    while (choice!=6)
    {
        printf("1. Insert at rear end\n2. Insert at front end\n3. Delete at front end\n4. Delete at rear end\n5. Display\n6. Exit\nENter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted at front: ");
            scanf("%d", &item);
            insertAtFront(q, item);
            break;
        case 2:
            printf("Enter item to be inserted at rear: ");
            scanf("%d", &item);
            insertAtRear(q, item);
            break;
        case 3:
            deleteFront(q);
            break;
        case 4:
            deleteRear(q);
            break;
        case 5: 
        display(q);
            break;
        case 6:
        printf("Exiting...\n");
            break;
        default:
        printf("Inavlid choice\n");
            break;
        }    
    }
}

void create(DQ *q){
    q->front=NULL;
    q->rear=NULL;
};

void insertAtFront(DQ *q, int item){
    
    dq *temp=(dq *)maloc(sizeof(dq));

    temp->data=item;
    temp->next=NULL;

    if (q->front==NULL) q->rear= temp;
    else temp->next=q->front;

    q->front=temp;
};

void insertAtRear(DQ *q, int item){
    dq *temp=(dq *)maloc(sizeof(dq));

    temp->data=item;
    temp->next=NULL;

    if (q->rear==NULL) q->front=temp;
    else q->rear->next=temp;

    q->rear=temp;
};

void deleteFront(DQ *q){

    dq *temp=q->front;
    int dItem=temp->data;
    
    q->front=temp->next;
    printf("%d\n", dItem);

    if (q->front==NULL) q->rear==NULL;
    else
    {
        free(temp);
        free(dItem);
    }
};

void deleteRear(DQ *q){

};

void display(DQ *q){
    
};
