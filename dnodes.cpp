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

// Function to count the number of nodes in the doubly linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Array of 5 values to create the doubly linked list
    int values[] = {10, 20, 30, 40, 50};

    // Create a doubly linked list
    struct Node* head = createDoublyLinkedList(values, 5);

    printf("Doubly Linked List: ");
    printList(head);

    // Count the number of nodes in the list
    int totalNodes = countNodes(head);
    printf("Total Number of Nodes: %d\n", totalNodes);

    return 0;
}

