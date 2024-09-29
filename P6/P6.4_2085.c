#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, char op) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = op;
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return '$'; 
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    return stack->array[stack->top];
}

int isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

void replaceBrackets(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

void infixToPostfix(char* exp, char* result) {
    Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;
    
    int k = 0;
    for (int i = 0; exp[i]; i++) {
        if (isOperand(exp[i]))
            result[k++] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                result[k++] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                result[k++] = pop(stack);
            push(stack, exp[i]);
        }
    }
    
    while (!isEmpty(stack))
        result[k++] = pop(stack);
    
    result[k] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);
    
    replaceBrackets(infix);
    
    char postfix[100];
    infixToPostfix(infix, postfix);
    
    reverse(postfix);
    
    strcpy(prefix, postfix);
}

int main() {
    char infix[100];
    char prefix[100];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Equivalent Prefix Expression is: %s\n", prefix);
    
    return 0;
}
