#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree (BST)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given data value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insertNode(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);     // Traverse left subtree
        printf("%d ", root->data);        // Visit root
        inorderTraversal(root->right);    // Traverse right subtree
    }
}

int main() {
    struct Node* root = NULL;

    // Construct the BST by inserting nodes
    root = insertNode(root, 50);  // Root node
    insertNode(root, 30);         // Left child of 50
    insertNode(root, 20);         // Left child of 30
    insertNode(root, 40);         // Right child of 30
    insertNode(root, 70);         // Right child of 50
    insertNode(root, 60);         // Left child of 70
    insertNode(root, 80);         // Right child of 70

    // Print the Inorder traversal (which should be in sorted order)
    printf("Inorder Traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

