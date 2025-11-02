/*
 * 8. Write a C program to implement the concept of stack using 
 * single linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer for the stack
struct Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an item onto the stack (insert at first)
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow. Cannot push.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an item from the stack (delete from first)
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow. Cannot pop.\n");
        return INT_MIN; // Return error value
    }
    struct Node* temp = top;
    int poppedData = temp->data;
    top = top->next;
    free(temp);
    return poppedData;
}

// Function to get the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return INT_MIN; // Return error value
    }
    return top->data;
}

// Function to display the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (top to bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function with menu
int main() {
    int choice, value;
    printf("--- Stack using Linked List ---\n");

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != INT_MIN) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != INT_MIN) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Exiting program.\n");
                // Free all remaining nodes
                while (!isEmpty()) {
                    pop();
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
