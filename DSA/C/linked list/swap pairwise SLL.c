/*
 * 5. Given a singly linked list of size N. The task is to swap elements 
 * in the linked list pairwise.
 * Example: 1->2->3->4 becomes 2->1->4->3
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to swap nodes pairwise
void swapPairwise(struct Node **head) {
    // If list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Use a dummy node to simplify edge case of swapping head
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = *head;

    struct Node* prev = dummy;
    struct Node* curr = *head;

    while (curr != NULL && curr->next != NULL) {
        // Nodes to be swapped
        struct Node* first = curr;
        struct Node* second = curr->next;

        // Perform swap
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move pointers for next iteration
        prev = first;
        curr = first->next;
    }

    // Update head
    *head = dummy->next;
    free(dummy);
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

// Main function to demonstrate pairwise swap
int main() {
    struct Node *head = NULL;

    printf("Creating list (even number of nodes)...\n");
    insertAtLast(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    printf("Original list:\n");
    displayList(head);
    swapPairwise(&head);
    printf("Swapped list:\n");
    displayList(head); // Expected: 2 -> 1 -> 4 -> 3 -> NULL
    freeList(&head);

    printf("\nCreating list (odd number of nodes)...\n");
    insertAtLast(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);
    printf("Original list:\n");
    displayList(head);
    swapPairwise(&head);
    printf("Swapped list:\n");
    displayList(head); // Expected: 2 -> 1 -> 4 -> 3 -> 5 -> NULL
    freeList(&head);

    return 0;
}
