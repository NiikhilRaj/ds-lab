#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} NODE;

int max(int a, int b);
int height(NODE *N);
NODE *newNode(int data);
NODE *rightRotate(NODE *y);
NODE *leftRotate(NODE *x);
int getBalance(NODE *N);
NODE *insert(NODE *node, int data);
NODE *search(NODE *root, int key);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE *findLargest(NODE *root);
NODE *findSmallest(NODE *root);
NODE *deleteNode(NODE *root, int key);
NODE *minValueNode(NODE *node);
int totalNodes(NODE *root);

int main()
{
    NODE *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node in AVL Tree\n");
        printf("2. Search a node in AVL Tree\n");
        printf("3. Display (preorder) in AVL Tree\n");
        printf("4. Display (inorder) in AVL Tree\n");
        printf("5. Display (postorder) in AVL Tree\n");
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

int height(NODE *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

NODE *newNode(int data)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

NODE *rightRotate(NODE *y)
{
    NODE *x = y->left;
    NODE *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NODE *leftRotate(NODE *x)
{
    NODE *y = x->right;
    NODE *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(NODE *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

NODE *insert(NODE *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

NODE *search(NODE *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            NODE *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            NODE *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

NODE *minValueNode(NODE *node)
{
    NODE *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

int totalNodes(NODE *root)
{
    if (root == NULL)
        return 0;
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}
