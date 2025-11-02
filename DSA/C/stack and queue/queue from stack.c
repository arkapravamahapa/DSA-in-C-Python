/*
6. Write a C program to implement queue using stack.
   (Minimal version)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// --- Stack Implementation ---
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(struct Stack* stack) { return stack->top == stack->capacity - 1; }
bool isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return; // Fail silently in minimal version
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

void freeStack(struct Stack* stack) {
    free(stack->array);
    free(stack);
}
// --- End Stack Implementation ---

// --- Queue using Stacks Structure ---
struct QueueUsingStacks {
    struct Stack* s1; // For enqueue
    struct Stack* s2; // For dequeue
};

// Function to create the queue
struct QueueUsingStacks* createQueue(unsigned capacity) {
    struct QueueUsingStacks* q = (struct QueueUsingStacks*)malloc(sizeof(struct QueueUsingStacks));
    q->s1 = createStack(capacity);
    q->s2 = createStack(capacity);
    return q;
}

// Enqueue operation (just push to s1)
void q_enqueue(struct QueueUsingStacks* q, int item) {
    if (isFull(q->s1)) {
        printf("Queue is full.\n");
        return;
    }
    push(q->s1, item);
    printf("Enqueued: %d\n", item);
}

// Dequeue operation (costly)
int q_dequeue(struct QueueUsingStacks* q) {
    // If s2 is empty, move all elements from s1 to s2
    if (isEmpty(q->s2)) {
        if (isEmpty(q->s1)) {
            printf("Queue is empty\n");
            return INT_MIN;
        }
        // Move elements from s1 to s2
        while (!isEmpty(q->s1)) {
            push(q->s2, pop(q->s1));
        }
    }
    
    // Pop from s2 (which now has the items in correct queue order)
    return pop(q->s2);
}

// Function to free the queue memory
void freeQueue(struct QueueUsingStacks* q) {
    freeStack(q->s1);
    freeStack(q->s2);
    free(q);
}

// Main function to demonstrate operations
int main() {
    printf("--- Q6: Queue using two Stacks (Minimal Demo) ---\n");
    
    struct QueueUsingStacks* q = createQueue(10);

    // Enqueue items
    q_enqueue(q, 10);
    q_enqueue(q, 20);
    q_enqueue(q, 30);

    // Dequeue and print items
    // Should print 10, then 20, then 30
    printf("Dequeued: %d\n", q_dequeue(q));
    printf("Dequeued: %d\n", q_dequeue(q));

    // Enqueue another item
    q_enqueue(q, 40);

    // Dequeue remaining items
    printf("Dequeued: %d\n", q_dequeue(q)); // Should be 30
    printf("Dequeued: %d\n", q_dequeue(q)); // Should be 40

    // Try to dequeue from empty queue
    printf("Dequeued: %d\n", q_dequeue(q)); // Should print "Queue is empty"

    // Free the memory
    freeQueue(q);

    return 0;
}
