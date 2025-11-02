/*
3. Write a C program to reverse a string using appropriate ADT.
   (ADT Used: Stack)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// --- Stack Implementation ---
struct Stack {
    int top;
    unsigned capacity;
    char* array; // Changed to char* for this problem
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char)); // char array
    return stack;
}

bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) return; // Should not happen if capacity is string length
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) return '\0'; // Return null char for error
    return stack->array[stack->top--];
}

void freeStack(struct Stack* stack) {
    free(stack->array);
    free(stack);
}
// --- End Stack Implementation ---

// Function to reverse a string using a stack
void reverseString(char* str) {
    int n = strlen(str);
    if (n == 0) return;

    struct Stack* stack = createStack(n);

    // Push all characters of string to stack
    for (int i = 0; i < n; i++)
        push(stack, str[i]);

    // Pop all characters of string and put them back to str
    for (int i = 0; i < n; i++)
        str[i] = pop(stack);
    
    freeStack(stack);
}

// Main function
int main() {
    char str[100];
    printf("--- Q3: Reverse String using Stack ---\n");
    printf("Enter a string: ");
    
    // Use fgets to read string safely, including spaces
    if (fgets(str, 100, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    
    return 0;
}
