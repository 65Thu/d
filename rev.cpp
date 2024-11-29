#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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

// Function to create a linked list
struct Node* createLinkedList(int values[], int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Function to print the linked list in original order
void printListOriginal(struct Node* head) {
    struct Node* temp = head;
    printf("Original Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the linked list in reverse order using recursion
void printListReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printListReverse(head->next);
    printf("%d -> ", head->data);
}

// Function to print the linked list in reverse order (using iteration)
void printListReverseIterative(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    // Reverse the linked list
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    // Print the reversed list
    printf("Reversed Linked List: ");
    while (prev != NULL) {
        printf("%d -> ", prev->data);
        prev = prev->next;
    }
    printf("NULL\n");
}

int main() {
    // Array of values to create the linked list
    int values[] = {10, 20, 30, 40, 50};

    // Create a linked list
    struct Node* head = createLinkedList(values, 5);

    // Print the original linked list
    printListOriginal(head);

    // Print the linked list in reverse order using recursion
    printf("Reversed Linked List (using recursion): ");
    printListReverse(head);
    printf("NULL\n");

    // Alternatively, print the reversed linked list using iteration
    printListReverseIterative(head);

    return 0;
}

