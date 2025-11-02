/*
 * 9. Write a C program to implement the concept of queue using 
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

// Queue structure holding front and rear
struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an item (insert at last)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow. Cannot enqueue.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("%d enqueued to queue.\n", data);
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d enqueued to queue.\n", data);
}

// Function to dequeue an item (delete from first)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow. Cannot dequeue.\n");
        return INT_MIN;
    }

    struct Node* temp = q->front;
    int dequeuedData = temp->data;

    // Move front one step ahead
    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedData;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    struct Queue* q = createQueue();
    int choice, value;
    printf("--- Queue using Linked List ---\n");

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != INT_MIN) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exiting program.\n");
                // Free all remaining nodes
                while (!isEmpty(q)) {
                    dequeue(q);
                }
                free(q);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
