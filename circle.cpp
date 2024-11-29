#include <stdio.h>
#define MAX 5 // Maximum size of the queue

// Define the structure of the queue
struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* q) {
    q->front = -1; // Queue is empty
    q->rear = -1;  // Queue is empty
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(struct CircularQueue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", data);
        return;
    }
    if (q->front == -1) {
        // If the queue is empty, set front to 0
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX; // Update rear in a circular manner
    q->arr[q->rear] = data;        // Add data to the queue
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the queue
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    if (q->front == q->rear) {
        // If the queue has only one element, reset front and rear
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Update front in a circular manner
    }
}

// Function to display the elements of the queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX; // Update index in a circular manner
    }
    printf("%d\n", q->arr[q->rear]); // Print the last element
}

int main() {
    struct CircularQueue q;
    initializeQueue(&q); // Initialize the circular queue

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

