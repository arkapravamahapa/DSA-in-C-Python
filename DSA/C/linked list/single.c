/*
 * 1. Write a C program to implement the following functions for single linked list:
 * • createList
 * • insertAtFirst
 * • insertAtLast
 * • insertAtAny
 * • displayList
 * Mention the necessary algorithm.
 */

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

// Function to display the linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Function to insert a node at the beginning
void insertAtFirst(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the first.\n", data);
}

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
    printf("Inserted %d at the last.\n", data);
}

// Function to insert a node at any position
void insertAtAny(struct Node **head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }
    if (pos == 1) {
        insertAtFirst(head, data);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    struct Node *temp = *head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d out of bounds.\n", pos);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", data, pos);
    }
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

// Main function to create and test the list
int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    // createList: We will build the list using the menu
    printf("Creating list (initially empty)...\n");

    while (1) {
        printf("\n--- SLL Insert Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtAny(&head, data, pos);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program. Freeing list...\n");
                freeList(&head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
