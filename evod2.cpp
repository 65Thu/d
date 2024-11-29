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

// Function to count even and odd nodes
void countEvenOddNodes(struct Node* head) {
    struct Node* temp = head;
    int evenCount = 0, oddCount = 0;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        temp = temp->next;
    }

    printf("Even nodes: %d\n", evenCount);
    printf("Odd nodes: %d\n", oddCount);
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
    // Array of values to create the linked list
    int values[] = {10, 15, 20, 25, 30};

    // Create a linked list
    struct Node* head = createLinkedList(values, 5);

    printf("Linked List: ");
    printList(head);

    // Count even and odd nodes
    countEvenOddNodes(head);

    return 0;
}

