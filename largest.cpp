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

// Function to find the node with the largest data value
void findLargestNode(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int maxData = head->data;
    int position = 1, maxPosition = 1;
    struct Node* temp = head->next;

    while (temp != NULL) {
        position++;
        if (temp->data > maxData) {
            maxData = temp->data;
            maxPosition = position;
        }
        temp = temp->next;
    }

    printf("Largest Data Value: %d\n", maxData);
    printf("Position: %d\n", maxPosition);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Array of 5 values to create the linked list
    int values[] = {10, 20, 30, 40, 50};

    // Create a linked list
    struct Node* head = createLinkedList(values, 5);

    printf("Linked List: ");
    printList(head);

    // Find and print the largest data value and its position
    findLargestNode(head);

    return 0;
}

