/*
4. Write a C program to implement the concept of double stack, where both
   ends can be used for operations.
   (Two stacks in a single dynamic array)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Double Stack structure
struct DoubleStack {
    int* array;
    int capacity;
    int top1, top2;
};

// Function to create a double stack
struct DoubleStack* createDoubleStack(int capacity) {
    struct DoubleStack* ds = (struct DoubleStack*)malloc(sizeof(struct DoubleStack));
    if (!ds) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    ds->capacity = capacity;
    ds->array = (int*)malloc(capacity * sizeof(int));
    if (!ds->array) {
        printf("Memory allocation failed\n");
        free(ds);
        return NULL;
    }
    ds->top1 = -1;        // Stack 1 grows from the left
    ds->top2 = capacity;  // Stack 2 grows from the right
    return ds;
}

// Push operation for Stack 1
void push1(struct DoubleStack* ds, int item) {
    // Check for overflow (collision)
    if (ds->top1 < ds->top2 - 1) {
        ds->array[++(ds->top1)] = item;
        printf("Pushed %d to Stack 1\n", item);
    } else {
        printf("Stack 1 Overflow (Collision)\n");
    }
}

// Push operation for Stack 2
void push2(struct DoubleStack* ds, int item) {
    // Check for overflow (collision)
    if (ds->top1 < ds->top2 - 1) {
        ds->array[--(ds->top2)] = item;
        printf("Pushed %d to Stack 2\n", item);
    } else {
        printf("Stack 2 Overflow (Collision)\n");
    }
}

// Pop operation for Stack 1
int pop1(struct DoubleStack* ds) {
    if (ds->top1 >= 0) {
        int item = ds->array[ds->top1--];
        return item;
    } else {
        printf("Stack 1 Underflow\n");
        return INT_MIN;
    }
}

// Pop operation for Stack 2
int pop2(struct DoubleStack* ds) {
    if (ds->top2 < ds->capacity) {
        int item = ds->array[ds->top2++];
        return item;
    } else {
        printf("Stack 2 Underflow\n");
        return INT_MIN;
    }
}

// Function to free the double stack memory
void freeDoubleStack(struct DoubleStack* ds) {
    free(ds->array);
    free(ds);
}

// Main function to drive the double stack operations
int main() {
    int choice, value, capacity;
    printf("--- Q4: Double Stack Implementation ---\n");
    printf("Enter total capacity of the array: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    struct DoubleStack* ds = createDoubleStack(capacity);
    if (!ds) {
        return 1;
    }

    while (1) {
        printf("\nDouble Stack Operations:\n");
        printf("1. PUSH to Stack 1\n");
        printf("2. PUSH to Stack 2\n");
        printf("3. POP from Stack 1\n");
        printf("4. POP from Stack 2\n");
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
                printf("Enter value for Stack 1: ");
                scanf("%d", &value);
                push1(ds, value);
                break;
            case 2:
                printf("Enter value for Stack 2: ");
                scanf("%d", &value);
                push2(ds, value);
                break;
            case 3:
                value = pop1(ds);
                if (value != INT_MIN) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2(ds);
                if (value != INT_MIN) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                freeDoubleStack(ds);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
