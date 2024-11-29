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

// Function to insert a node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node is the head
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link the new node at the end
    return head;
}

// Function to insert a node at a specific position in the list
struct Node* insertSpecificPos(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        // If position is 1, insert at the beginning
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next; // Traverse to the node before the target position
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node from a specific position in the list
struct Node* deleteSpecificPos(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    if (position == 1) {
        // Delete the head node
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next; // Traverse to the target node
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    prev->next = temp->next; // Unlink the target node
    free(temp);              // Free the memory of the deleted node
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert elements at the end
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head); // Output: 10 -> 20 -> 30 -> NULL

    // Insert an element at a specific position
    head = insertSpecificPos(head, 25, 2);
    printList(head); // Output: 10 -> 25 -> 20 -> 30 -> NULL

    // Delete an element at a specific position
    head = deleteSpecificPos(head, 3);
    printList(head); // Output: 10 -> 25 -> 30 -> NULL

    return 0;
}

