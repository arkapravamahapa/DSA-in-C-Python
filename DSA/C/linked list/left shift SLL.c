/*
 * 3. Given a singly linked list of size N. The task is to left-shift 
 * the linked list by k nodes, where k is a given positive integer 
 * smaller than or equal to length of the linked list.
 * (This is also known as rotating the list).
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to left-shift (rotate) the list by k positions
void leftShiftList(struct Node **head, int k) {
    if (*head == NULL || k == 0) {
        return; // No rotation needed
    }

    // 1. Find the last node and count N (size of list)
    int n = 1;
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
        n++;
    }

    // If k is a multiple of n, no change
    if (k % n == 0) {
        return;
    }
    // Adjust k if it's larger than n
    k = k % n;
    
    // 2. Find the k-th node. This will be the new last node.
    struct Node* newLastNode = *head;
    for (int i = 1; i < k; i++) {
        newLastNode = newLastNode->next;
    }

    // 3. The node *after* the k-th node is the new head
    struct Node* newHead = newLastNode->next;

    // 4. Set the k-th node as the new tail
    newLastNode->next = NULL;

    // 5. Connect the old last node to the old head
    lastNode->next = *head;

    // 6. Update the head pointer
    *head = newHead;
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

void freeList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function to demonstrate left-shift
int main() {
    struct Node *head = NULL;

    printf("Creating list...\n");
    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);
    insertAtLast(&head, 50);

    printf("Original list:\n");
    displayList(head);

    int k = 2;
    printf("\nLeft-shifting list by %d nodes...\n", k);
    leftShiftList(&head, k);

    printf("Shifted list:\n");
    displayList(head); // Expected: 30 -> 40 -> 50 -> 10 -> 20 -> NULL

    freeList(&head);
    return 0;
}
