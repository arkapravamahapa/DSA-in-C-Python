
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed\n");
        free(stack);
        return NULL;
    }
    return stack;
}

// Stack is full when top is equal to the last index
bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

// Function to free the stack memory
void freeStack(struct Stack* stack) {
    free(stack->array);
    free(stack);
}

// Main function to drive the stack operations
int main() {
    int choice, value, capacity;
    printf("--- Stack Implementation ---\n");
    printf("Enter capacity of the stack: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }
    
    struct Stack* stack = createStack(capacity);
    if (!stack) {
        return 1; // Exit if stack creation failed
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != INT_MIN) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(stack);
                if (value != INT_MIN) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting program.\n");
                freeStack(stack);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
