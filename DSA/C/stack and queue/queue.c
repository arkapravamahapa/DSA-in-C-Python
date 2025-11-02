/*
2. Write a C program to implement queue using dynamic array. 
   Execute all the necessary functions of queue.
   (Note: The standard implementation of a queue with a dynamic array 
   is a circular queue to achieve O(1) enqueue/dequeue.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
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
bool isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear):\n");
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Function to free the queue memory
void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}

// Main function to drive the queue operations
int main() {
    int choice, value, capacity;
    printf("--- Queue Implementation ---\n");
    printf("Enter capacity of the queue: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    struct Queue* queue = createQueue(capacity);
    if (!queue) {
        return 1; // Exit if queue creation failed
    }

    while (1) {
        printf("\nQueue Operations:\n");
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
                freeQueue(queue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
