/*
 * 6. Write a C program to print the odd number and even number nodes 
 * separately from a single linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// --- Core Function ---

// Function to print even and odd numbers separately
void printOddEven(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    // First pass: Print Even Numbers
    printf("Even numbers: ");
    int evenFound = 0;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            printf("%d ", temp->data);
            evenFound = 1;
        }
        temp = temp->next;
    }
    if (!evenFound) printf("None");
    printf("\n");

    // Reset temp to head for the second pass
    temp = head;

    // Second pass: Print Odd Numbers
    printf("Odd numbers:  ");
    int oddFound = 0;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("%d ", temp->data);
            oddFound = 1;
        }
        temp = temp->next;
    }
    if (!oddFound) printf("None");
    printf("\n");
}

// --- Helper Functions (for setup and display) ---

// Function to insert a node at the end
void insertAtLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
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
    printf("Full List: ");
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

// Main function to demonstrate the odd/even print
int main() {
    struct Node *head = NULL;
    int data;

    printf("Enter numbers to add to the list (enter -1 to stop):\n");
    while (1) {
        printf("Enter number: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertAtLast(&head, data);
    }
    
    printf("\n");
    displayList(head);
    printf("\n--- Odd/Even Separation ---\n");
    printOddEven(head);

    // Free the list memory
    freeList(&head);
    return 0;
}
