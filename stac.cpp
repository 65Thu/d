#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top; // Link the new node to the previous top
    top = newNode;       // Update top to the new node
    return top;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return NULL;
    }
    struct Node* temp = top;
    top = top->next; // Update top to the next node
    printf("Popped element: %d\n", temp->data);
    free(temp);      // Free memory of the popped node
    return top;
}

// Function to peek (view the top element) of the stack
void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL; // Initialize the stack as empty

    // Perform stack operations
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top); // Output: 30 -> 20 -> 10 -> NULL

    peek(top);    // Output: Top element: 30

    top = pop(top); // Pops 30
    display(top);   // Output: 20 -> 10 -> NULL

    top = pop(top); // Pops 20
    top = pop(top); // Pops 10
    top = pop(top); // Stack Underflow

    return 0;
}

