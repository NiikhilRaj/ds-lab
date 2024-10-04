#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* insert(NODE* node, int data);
NODE* search(struct Node* root, int key);
void preorder(NODE* root);
void inorder(NODE* root);
void postorder(NODE* root);
NODE* findLargest(NODE* root);
NODE* findSmallest(NODE* root);
NODE* deleteNode(NODE* root, int key);
NODE* minValueNode(NODE* node);

int main() {
    NODE* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node in BST\n");
        printf("2. Search a node in BST\n");
        printf("3. Display (preorder) in BST\n");
        printf("4. Display (inorder) in BST\n");
        printf("5. Display (postorder) in BST\n");
        printf("6. Find largest element\n");
        printf("7. Find smallest element\n");
        printf("8. Delete the element\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                if (root != NULL) {
                    NODE* largest = findLargest(root);
                    printf("Largest element: %d\n", largest->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 7:
                if (root != NULL) {
                    NODE* smallest = findSmallest(root);
                    printf("Smallest element: %d\n", smallest->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

NODE* insert(NODE* node, int data) {
    if (node == NULL) {
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

NODE* search(NODE* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

void preorder(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

NODE* findLargest(NODE* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

NODE* findSmallest(NODE* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

NODE* deleteNode(NODE* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
        NODE* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

NODE* minValueNode(NODE* node) {
    NODE* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
