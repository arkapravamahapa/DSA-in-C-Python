/*
7. Write a C program to implement circular queue.
   (This is the same as the standard dynamic array queue from Q2,
   provided here as a separate, complete program.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Circular Queue structure
struct CQueue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a circular queue
struct CQueue* createCQueue(unsigned capacity) {
    struct CQueue* queue = (struct CQueue*)malloc(sizeof(struct CQueue));
    if (!queue) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Initialize rear to last index
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation failed\n");
        free(queue);
        return NULL;
    }
    return queue;
}

// Queue is full when size becomes equal to the capacity
bool isFull(struct CQueue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
bool isEmpty(struct CQueue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(struct CQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Circular Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to circular queue\n", item);
}

// Function to remove an item from queue
int dequeue(struct CQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct CQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct CQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

// Function to display the queue
void display(struct CQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements (front to rear):\n");
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Function to free the queue memory
void freeCQueue(struct CQueue* queue) {
    free(queue->array);
    free(queue);
}

// Main function to drive the circular queue operations
int main() {
    int choice, value, capacity;
    printf("--- Q7: Circular Queue Implementation ---\n");
    printf("Enter capacity of the circular queue: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    struct CQueue* queue = createCQueue(capacity);
    if (!queue) {
        return 1; // Exit if queue creation failed
    }

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. REAR\n");
        printf("5. DISPLAY\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != INT_MIN) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = front(queue);
                if (value != INT_MIN) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                value = rear(queue);
                if (value != INT_MIN) {
                    printf("Rear element: %d\n", value);
                }
                break;
            case 5:
                display(queue);
                break;
            case 6:
                printf("Exiting program.\n");
                freeCQueue(queue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
