#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item[10];
    int top;
} NODE;

int isFull(NODE *stack) {
    return stack->top == 9;
}

int isEmpty(NODE *stack) {
    return stack->top == -1;
}

void push(NODE *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->item[stack->top] = data;
    printf("%d pushed onto stack.\n", data);
}

int pop(NODE *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;  
    }
    int poppedItem = stack->item[stack->top];
    stack->top--;
    return poppedItem;
}

int peep(NODE *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; 
    }
    return stack->item[stack->top];
}

void display(NODE *stack){
    if (isEmpty(stack))
    {
        printf("Empty stack\n");
    }
    while (stack->top!=-1)
    {
        printf("%d", stack->item);
        stack=pop(stack);
    }
};


int main() {
    NODE stack;
    stack.top = -1;  

     int choice, data;

    while (1) {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
