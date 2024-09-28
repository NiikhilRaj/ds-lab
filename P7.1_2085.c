#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;

void push(int item);
void pop();
void display();

int main()
{
    int choice, item;
    printf("1. Add a node in the queue\n2. Delete a node in the queue\n3. Traverse \n4. Exit\n Enter your choice: ");
    scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting..\n");
            break;
        default:
            printf("INvalid coice!\n");
            break;
        }
    
    return 0;
}

void push(int item){
    NODE *ptr;
    ptr=(NODE *)malloc(sizeof(NODE));
    ptr->data=item;
    ptr->next=NULL;
    if ((front==NULL)&(rear==NULL))
    {
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("Node is Inserted\n");
};
void pop(){
    if (front==NULL)
    {
        printf("\nUnderflow\n");
        return;
    }
    else{
        NODE *temp=front;
        int tempdtata= front->data;
        front=front->next;
        free(temp);
        printf("%d", tempdtata);
    }
};
void display(){
    NODE *temp;
    if ((front==NULL)&&(rear==NULL))
    {
        printf("\nQUeue is empty\n");
        return;
    }
    else{
        printf("THe queue is \n");
        temp = front;
        while (temp)
        {
            printf("%d-->", temp->data);
            temp= temp->next;
        }
        printf("NULL\n");
    } 
};