#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **top, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack.\n", data);
}


int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;  
    }
    Node *temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("%d popped from stack.\n", poppedData);
    return poppedData;
}

void display(Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    Node *stack = NULL;  
    int choice, data;

    while (1) {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(stack);
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
