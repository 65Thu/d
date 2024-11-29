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

// Function to create a linked list with 5 nodes
struct Node* createLinkedList(int values[]) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for (int i = 0; i < 5; i++) {
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

// Function to concatenate two linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
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
    // Values for the two lists
    int values1[] = {1, 2, 3, 4, 5};
    int values2[] = {6, 7, 8, 9, 10};

    // Create two linked lists
    struct Node* list1 = createLinkedList(values1);
    struct Node* list2 = createLinkedList(values2);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Concatenate the two lists
    struct Node* concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    printList(concatenatedList);

    return 0;
}

