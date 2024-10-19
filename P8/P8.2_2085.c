#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} NODE;

typedef struct Stack
{
    NODE *node;
    struct Stack *next;
} STACK;

void push(STACK **top, NODE *node)
{
    STACK *newNode = (STACK *)malloc(sizeof(STACK));
    newNode->node = node;
    newNode->next = *top;
    *top = newNode;
}

NODE *pop(STACK **top)
{
    if (*top == NULL)
        return NULL;
    STACK *temp = *top;
    *top = (*top)->next;
    NODE *node = temp->node;
    free(temp);
    return node;
}

NODE *insert(NODE *node, int data);
NODE *search(NODE *root, int key);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE *findLargest(NODE *root);
NODE *findSmallest(NODE *root);
NODE *deleteNode(NODE *root, int key);
NODE *minValueNode(NODE *node);
int height(NODE *root);
int totalNodes(NODE *root);

int main()
{
    NODE *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node in BST\n");
        printf("2. Search a node in BST\n");
        printf("3. Display (preorder) in BST\n");
        printf("4. Display (inorder) in BST\n");
        printf("5. Display (postorder) in BST\n");
        printf("6. Find largest element\n");
        printf("7. Find smallest element\n");
        printf("8. Delete the element\n");
        printf("9. Find height of the tree\n");
        printf("10. Find total number of nodes\n");
        printf("11. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
                printf("Node found.\n");
            else
                printf("Node not found.\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            if (root != NULL)
            {
                NODE *largest = findLargest(root);
                printf("Largest element: %d\n", largest->data);
            }
            else
            {
                printf("Tree is empty.\n");
            }
            break;
        case 7:
            if (root != NULL)
            {
                NODE *smallest = findSmallest(root);
                printf("Smallest element: %d\n", smallest->data);
            }
            else
            {
                printf("Tree is empty.\n");
            }
            break;
        case 8:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 9:
            printf("Height of the tree: %d\n", height(root));
            break;
        case 10:
            printf("Total number of nodes: %d\n", totalNodes(root));
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

NODE *insert(NODE *node, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (node == NULL)
        return newNode;

    NODE *parent = NULL, *current = node;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return node;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return node;
}

NODE *search(NODE *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

void preorder(NODE *root)
{
    if (root == NULL)
        return;

    STACK *stack = NULL;
    push(&stack, root);

    while (stack != NULL)
    {
        NODE *node = pop(&stack);
        printf("%d ", node->data);

        if (node->right)
            push(&stack, node->right);
        if (node->left)
            push(&stack, node->left);
    }
}

void inorder(NODE *root)
{
    STACK *stack = NULL;
    NODE *current = root;

    while (current != NULL || stack != NULL)
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorder(NODE *root)
{
    if (root == NULL)
        return;

    STACK *stack1 = NULL, *stack2 = NULL;
    push(&stack1, root);

    while (stack1 != NULL)
    {
        NODE *node = pop(&stack1);
        push(&stack2, node);

        if (node->left)
            push(&stack1, node->left);
        if (node->right)
            push(&stack1, node->right);
    }

    while (stack2 != NULL)
    {
        NODE *node = pop(&stack2);
        printf("%d ", node->data);
    }
}

NODE *findLargest(NODE *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

NODE *findSmallest(NODE *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

NODE *deleteNode(NODE *root, int key)
{
    NODE *parent = NULL, *current = root;

    while (current != NULL && current->data != key)
    {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return root;

    if (current->left == NULL || current->right == NULL)
    {
        NODE *newCurr;

        if (current->left == NULL)
            newCurr = current->right;
        else
            newCurr = current->left;

        if (parent == NULL)
            return newCurr;

        if (current == parent->left)
            parent->left = newCurr;
        else
            parent->right = newCurr;

        free(current);
    }
    else
    {
        NODE *p = NULL;
        NODE *temp;

        temp = current->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }

        if (p != NULL)
            p->left = temp->right;
        else
            current->right = temp->right;

        current->data = temp->data;
        free(temp);
    }

    return root;
}

NODE *minValueNode(NODE *node)
{
    NODE *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

int height(NODE *root)
{
    if (root == NULL)
        return 0;

    STACK *stack = NULL;
    push(&stack, root);
    int height = 0;

    while (stack != NULL)
    {
        int nodeCount = 0;
        STACK *tempStack = NULL;

        while (stack != NULL)
        {
            NODE *node = pop(&stack);
            if (node->left)
                push(&tempStack, node->left);
            if (node->right)
                push(&tempStack, node->right);
            nodeCount++;
        }

        stack = tempStack;
        if (nodeCount > 0)
            height++;
    }

    return height;
}

int totalNodes(NODE *root)
{
    if (root == NULL)
        return 0;

    STACK *stack = NULL;
    push(&stack, root);
    int count = 0;

    while (stack != NULL)
    {
        NODE *node = pop(&stack);
        count++;

        if (node->right)
            push(&stack, node->right);
        if (node->left)
            push(&stack, node->left);
    }

    return count;
}
