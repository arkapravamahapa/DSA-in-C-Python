/*
 * 6. Write a C program to detect a loop in a single linked list.
 * (Using Floyd's Cycle-Finding Algorithm - Tortoise and Hare)
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to detect a loop
int detectLoop(struct Node *head) {
    struct Node *slowPtr = head;
    struct Node *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;      // Moves 1 step
        fastPtr = fastPtr->next->next; // Moves 2 steps

        // If slow and fast pointers meet, a loop exists
        if (slowPtr == fastPtr) {
            return 1; // Loop found
        }
    }
    
    return 0; // No loop
}

// --- Helper Functions (for setup and display) ---

void insertAtLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

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

// Note: freeList will cause infinite loop if a loop exists!
// Only call it on a non-looped list.

// Main function to demonstrate loop detection
int main() {
    struct Node *loopedList = NULL;

    printf("--- Test 1: List with a loop ---\n");
    insertAtLast(&loopedList, 10);
    insertAtLast(&loopedList, 20);
    insertAtLast(&loopedList, 30);
    insertAtLast(&loopedList, 40);
    insertAtLast(&loopedList, 50);
    
    // Manually create a loop: 50 -> 30
    printf("Creating loop: 50 -> 30\n");
    struct Node* node30 = loopedList->next->next;
    struct Node* node50 = loopedList->next->next->next->next;
    node50->next = node30;
    
    if (detectLoop(loopedList)) {
        printf("Result: Loop detected!\n");
    } else {
        printf("Result: No loop detected.\n");
    }
    
    // We cannot free this list normally. 
    // We'd have to break the loop first. For this demo, we'll "leak" it.
    // To properly free, we'd need to set node50->next = NULL, then freeList.

    printf("\n--- Test 2: List without a loop ---\n");
    struct Node *normalList = NULL;
    insertAtLast(&normalList, 1);
    insertAtLast(&normalList, 2);
    insertAtLast(&normalList, 3);
    displayList(normalList);

    if (detectLoop(normalList)) {
        printf("Result: Loop detected!\n");
    } else {
        printf("Result: No loop detected.\n");
    }

    // Free the normal list
    // freeList(&normalList); // This function is not in this file,
    // but in a real program you would free it.

    return 0;
}
