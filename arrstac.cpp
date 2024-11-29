#include <stdio.h>
#define MAX 100 // Maximum size of the stack

// Define the stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1; // Set top to -1, indicating the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    stack->arr[++stack->top] = data; // Increment top and add the element
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return;
    }
    printf("Popped element: %d\n", stack->arr[stack->top--]);
}

// Function to peek (view the top element) of the stack
void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element: %d\n", stack->arr[stack->top]);
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack); // Initialize the stack

    // Perform stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack); // Output: 30 20 10

    peek(&stack);    // Output: Top element: 30

    pop(&stack);     // Pops 30
    display(&stack); // Output: 20 10

    pop(&stack);     // Pops 20
    pop(&stack);     // Pops 10
    pop(&stack);     // Stack Underflow

    return 0;
}

