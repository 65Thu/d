#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the tree
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

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Traverse left subtree
        postorderTraversal(root->right); // Traverse right subtree
        printf("%d ", root->data);      // Visit root
    }
}

int main() {
    struct Node* root = NULL;

    // Manually creating nodes for the tree
    root = createNode(1);         // Root node
    root->left = createNode(2);    // Left child of root
    root->right = createNode(3);   // Right child of root
    root->left->left = createNode(4);   // Left child of left child
    root->left->right = createNode(5);  // Right child of left child

    // Print Inorder Traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Print Postorder Traversal
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

