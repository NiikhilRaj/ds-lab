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

int main() {
    NODE stack;
    stack.top = -1;  

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peep(&stack));

    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));

    printf("Top element is %d\n", peep(&stack));

    return 0;
}
