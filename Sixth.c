#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value not allowed!\n");

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("The element is not a leaf node, cannot delete!\n");
            return root;
        }
    }

    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Search an element in BST\n");
    printf("2. Insert an element in BST\n");
    printf("3. Delete a leaf element in BST\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &val);
                if (search(root, val) != NULL)
                    printf("Element Found\n");
                else
                    printf("Element Not Found\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                printf("After deletion, Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}