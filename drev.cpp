#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node* createDoublyLinkedList(int values[], int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// Function to print the doubly linked list in original order
void printListOriginal(struct Node* head) {
    struct Node* temp = head;
    printf("Original Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list in reverse order
void printListReverse(struct Node* head) {
    struct Node* temp = head;

    // Traverse to the last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    // Print the list in reverse order
    printf("Reversed Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    // Array of values to create the doubly linked list
    int values[] = {10, 20, 30, 40, 50};

    // Create the doubly linked list
    struct Node* head = createDoublyLinkedList(values, 5);

    // Print the original doubly linked list
    printListOriginal(head);

    // Print the doubly linked list in reverse order
    printListReverse(head);

    return 0;
}

