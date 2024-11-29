#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
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
    newNode->prev = temp; // Set the previous pointer of the new node
    return head;
}

// Function to insert a node at a specific position
struct Node* insertSpecificPos(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        // Insert at the beginning
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
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
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to delete a node at a specific position
struct Node* deleteSpecificPos(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next; // Move head to the next node
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp); // Free memory of the old head
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next; // Traverse to the node at the target position
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp); // Free memory of the deleted node
    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty doubly linked list

    // Insert elements at the end
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head); // Output: 10 <-> 20 <-> 30 <-> NULL

    // Insert an element at a specific position
    head = insertSpecificPos(head, 15, 2);
    printList(head); // Output: 10 <-> 15 <-> 20 <-> 30 <-> NULL

    // Delete an element at a specific position
    head = deleteSpecificPos(head, 3);
    printList(head); // Output: 10 <-> 15 <-> 30 <-> NULL

    return 0;
}

