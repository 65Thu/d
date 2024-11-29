#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a singly linked list
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

// Function to create a singly linked list from an array of values
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete nodes which are multiples of 3
struct Node* deleteMultiplesOfThree(struct Node* head) {
    struct Node *temp = head, *prev = NULL;

    // Traverse the list
    while (temp != NULL) {
        // If the current node's data is a multiple of 3
        if (temp->data % 3 == 0) {
            // If it is the first node
            if (prev == NULL) {
                head = temp->next;  // Move head to the next node
                free(temp);         // Free the memory of the deleted node
                temp = head;        // Move temp to the new head
            } else {
                prev->next = temp->next;  // Bypass the current node
                free(temp);               // Free the memory of the deleted node
                temp = prev->next;        // Move temp to the next node
            }
        } else {
            // If not a multiple of 3, move to the next node
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    // Array of values to create the linked list
    int values[] = {10, 12, 15, 20, 21, 25, 30, 40};

    // Create a linked list
    struct Node* head = createLinkedList(values, 8);

    // Print the original linked list
    printList(head);

    // Delete nodes which are multiples of 3
    head = deleteMultiplesOfThree(head);

    // Print the updated linked list
    printList(head);

    return 0;
}

