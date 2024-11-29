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

// Function to create a linked list with given values
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

// Function to copy a linked list
struct Node* copyLinkedList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* newHead = NULL;
    struct Node* newTail = NULL;

    while (head != NULL) {
        struct Node* newNode = createNode(head->data);
        if (newHead == NULL) {
            newHead = newNode;
            newTail = newHead;
        } else {
            newTail->next = newNode;
            newTail = newTail->next;
        }
        head = head->next;
    }

    return newHead;
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
    // Create a linked list
    int values[] = {1, 2, 3, 4, 5};
    struct Node* originalList = createLinkedList(values, 5);

    printf("Original List: ");
    printList(originalList);

    // Copy the linked list
    struct Node* copiedList = copyLinkedList(originalList);

    printf("Copied List: ");
    printList(copiedList);

    return 0;
}

