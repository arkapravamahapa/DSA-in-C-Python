/*
 * 3. Write a C program to implement all the insert and delete functions 
 * and display function along with an appropriate menu for a single linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// --- Utility Functions ---

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

// Function to count nodes
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
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

// --- Insert Functions ---

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

// --- Delete Functions ---

// Function to delete the first node
void deleteFromFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    int deletedData = temp->data;
    *head = (*head)->next;
    free(temp);
    printf("Deleted %d from first.\n", deletedData);
}

// Function to delete the last node
void deleteFromLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp->next == NULL) { // Single node
        int deletedData = temp->data;
        free(temp);
        *head = NULL;
        printf("Deleted %d from last.\n", deletedData);
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int deletedData = temp->data;
    prev->next = NULL;
    free(temp);
    printf("Deleted %d from last.\n", deletedData);
}

// Function to delete a node from any position
void deleteFromAny(struct Node **head, int pos) {
    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos == 1) {
        deleteFromFirst(head);
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position %d out of bounds.\n", pos);
    } else {
        prev->next = temp->next;
        int deletedData = temp->data;
        free(temp);
        printf("Deleted %d from position %d.\n", deletedData, pos);
    }
}

// Main function with comprehensive menu
int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Singly Linked List (SLL) Menu ---\n");
        printf("--- Insert ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("--- Delete ---\n");
        printf("4. Delete from First\n");
        printf("5. Delete from Last\n");
        printf("6. Delete from Any Position\n");
        printf("--- Utility ---\n");
        printf("7. Display List\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Enter data: ");
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
                deleteFromFirst(&head);
                break;
            case 5:
                deleteFromLast(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromAny(&head, pos);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 9:
                printf("Exiting program. Freeing list...\n");
                freeList(&head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
