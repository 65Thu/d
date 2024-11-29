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

// Function to split a list into odd-position and even-position nodes
void splitOddEven(struct Node* head, struct Node** oddList, struct Node** evenList) {
    if (head == NULL) {
        *oddList = NULL;
        *evenList = NULL;
        return;
    }

    struct Node* oddTemp = NULL;
    struct Node* evenTemp = NULL;

    int position = 1;
    while (head != NULL) {
        struct Node* newNode = createNode(head->data);
        if (position % 2 != 0) { // Odd position
            if (*oddList == NULL) {
                *oddList = newNode;
                oddTemp = *oddList;
            } else {
                oddTemp->next = newNode;
                oddTemp = oddTemp->next;
            }
        } else { // Even position
            if (*evenList == NULL) {
                *evenList = newNode;
                evenTemp = *evenList;
            } else {
                evenTemp->next = newNode;
                evenTemp = evenTemp->next;
            }
        }
        head = head->next;
        position++;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list with 10 nodes
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct Node* head = createLinkedList(values, 10);

    printf("Original List: ");
    printList(head);

    // Split the list into odd and even position lists
    struct Node* oddList = NULL;
    struct Node* evenList = NULL;

    splitOddEven(head, &oddList, &evenList);

    printf("Odd Position List: ");
    printList(oddList);

    printf("Even Position List: ");
    printList(evenList);

    return 0;
}

