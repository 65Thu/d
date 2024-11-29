#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure of a queue
struct Queue {
    struct Node* front; // Points to the front of the queue
    struct Node* rear;  // Points to the rear of the queue
};

// Function to initialize the queue
struct Queue* initializeQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

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

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        // If the queue is empty, front and rear point to the new node
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Add the new node at the rear of the queue
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        // If the queue becomes empty, rear is also set to NULL
        q->rear = NULL;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp); // Free memory of the dequeued node
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = initializeQueue(); // Initialize an empty queue

    // Perform queue operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q); // Output: 10 -> 20 -> 30 -> NULL

    dequeue(q); // Dequeues 10
    display(q); // Output: 20 -> 30 -> NULL

    dequeue(q); // Dequeues 20
    dequeue(q); // Dequeues 30
    dequeue(q); // Queue Underflow

    return 0;
}

