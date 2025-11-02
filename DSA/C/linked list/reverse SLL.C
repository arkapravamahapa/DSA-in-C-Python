/*
 * 1. Write a C program to reverse an already created single linked list.
 * Mention the necessary algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * --- Algorithm to Reverse a Linked List (Iterative) ---
 *
 * 1.  Initialize three pointers:
 * - `prevNode` (points to the previous node, starts at `NULL`).
 * - `currentNode` (points to the current node, starts at `head`).
 * - `nextNode` (points to the next node, starts at `NULL`).
 *
 * 2.  Iterate through the list while `currentNode` is not `NULL`:
 * a. Store the next node in `nextNode`:
 * `nextNode = currentNode->next;`
 *
 * b. Reverse the current node's pointer to point to the previous node:
 * `currentNode->next = prevNode;`
 *
 * c. Move the pointers one step forward for the next iteration:
 * `prevNode = currentNode;`
 * `currentNode = nextNode;`
 *
 * 3.  After the loop finishes, `currentNode` will be `NULL`, and `prevNode` 
 * will be at the new head (the former tail).
 *
 * 4.  Update the head of the list to `prevNode`:
 * `*head = prevNode;`
 */

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse the linked list
void reverseList(struct Node **head) {
    struct Node *prevNode = NULL;
    struct Node *currentNode = *head;
    struct Node *nextNode = NULL;

    while (currentNode != NULL) {
        // Store the next node
        nextNode = currentNode->next;
        // Reverse the current node's pointer
        currentNode->next = prevNode;
        // Move pointers one step forward
        prevNode = currentNode;
        currentNode = nextNode;
    }
    // Update the head to the new front of the list
    *head = prevNode;
}

// --- Helper Functions (for setup and display) ---

// Function to insert a node at the end
void insertAtLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function to demonstrate the reversal
int main() {
    struct Node *head = NULL;

    printf("Creating list...\n");
    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);

    printf("Original list:\n");
    displayList(head);

    printf("\nReversing list...\n");
    reverseList(&head);

    printf("Reversed list:\n");
    displayList(head);

    freeList(&head);
    return 0;
}
