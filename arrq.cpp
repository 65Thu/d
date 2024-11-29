#include <stdio.h>
#define MAX 5 // Maximum size of the queue

// Define the structure of the queue
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = -1; // Front points to -1 indicating the queue is empty
    q->rear = -1;  // Rear points to -1 indicating the queue is empty
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", data);
        return;
    }
    if (q->front == -1) {
        // If the queue is empty, set front to 0
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data; // Add the data at the rear
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    if (q->front == q->rear) {
        // If the queue has only one element, reset front and rear
        q->front = q->rear = -1;
    } else {
        q->front++; // Move front pointer to the next element
    }
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q); // Initialize an empty queue

    // Perform queue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q); // Output: 10 20 30 40 50

    enqueue(&q, 60); // Output: Queue Overflow!

    dequeue(&q);     // Dequeues 10
    display(&q);     // Output: 20 30 40 50

    dequeue(&q);     // Dequeues 20
    dequeue(&q);     // Dequeues 30
    dequeue(&q);     // Dequeues 40
    dequeue(&q);     // Dequeues 50
    dequeue(&q);     // Output: Queue Underflow!

    return 0;
}

