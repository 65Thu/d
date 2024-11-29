#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX 100

// Stack structure to store parentheses
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1; // Stack is empty initially
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char ch) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++(stack->top)] = ch;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

// Function to check if the given parentheses are balanced
int isBalanced(char* expr) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If it's an opening parenthesis, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // If it's a closing parenthesis, check for match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0; // If the stack is empty, no opening parenthesis to match
            }
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return 0; // Mismatched parentheses
            }
        }
    }

    // If the stack is empty, the parentheses are balanced
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    // Get the input expression from the user
    printf("Enter an expression with parentheses: ");
    scanf("%s", expr);

    // Check if the parentheses are balanced
    if (isBalanced(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}

