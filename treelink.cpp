#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit root
        preorder(root->left);       // Traverse left subtree
        preorder(root->right);      // Traverse right subtree
    }
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);        // Traverse left subtree
        printf("%d ", root->data);  // Visit root
        inorder(root->right);       // Traverse right subtree
    }
}

int main() {
    // Create tree nodes
    struct Node* root = createNode(1);            // Root node
    struct Node* leftChild = createNode(2);       // Left child of root
    struct Node* rightChild = createNode(3);      // Right child of root
    struct Node* leftLeftChild = createNode(4);   // Left child of the left child
    struct Node* leftRightChild = createNode(5);  // Right child of the left child

    // Construct the tree
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftLeftChild;
    leftChild->right = leftRightChild;

    // Print tree traversals
    printf("Preorder Traversal: ");
    preorder(root);  // Preorder traversal (Root, Left, Right)
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);   // Inorder traversal (Left, Root, Right)
    printf("\n");

    return 0;
}

