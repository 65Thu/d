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

// Function to split the linked list
void splitLinkedList(struct Node* head, int splitIndex, struct Node** list1, struct Node** list2) {
    if (head == NULL) {
        *list1 = NULL;
        *list2 = NULL;
        return;
    }

    *list1 = head;
    struct Node* temp = head;

    // Traverse the list to the split point
    for (int i = 1; i < splitIndex && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        *list2 = temp->next;
        temp->next = NULL;  // Break the link to split the lists
    }
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
    // Create a linked list with 10 nodes
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct Node* head = createLinkedList(values, 10);

    printf("Original List: ");
    printList(head);

    // Split the list into two parts: 4 nodes and 6 nodes
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    splitLinkedList(head, 4, &list1, &list2);

    printf("First List (4 nodes): ");
    printList(list1);

    printf("Second List (6 nodes): ");
    printList(list2);

    return 0;
}

