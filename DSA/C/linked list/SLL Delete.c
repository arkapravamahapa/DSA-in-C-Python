

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// --- Helper Functions (for setup and display) ---

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

// Function to free the entire list
void freeList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
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

    // Handle single node list
    if (temp->next == NULL) {
        int deletedData = temp->data;
        free(temp);
        *head = NULL;
        printf("Deleted %d from last.\n", deletedData);
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    int deletedData = temp->data;
    prev->next = NULL; // Unlink the last node
    free(temp);        // Free it
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
        prev->next = temp->next; // Unlink the node
        int deletedData = temp->data;
        free(temp);              // Free it
        printf("Deleted %d from position %d.\n", deletedData, pos);
    }
}

// Main function to create and test the list
int main() {
    struct Node *head = NULL;
    int choice, pos;

    // createList: Pre-populate the list for deletion demo
    printf("Creating and populating list...\n");
    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);
    insertAtLast(&head, 50);
    displayList(head);

    while (1) {
        printf("\n--- SLL Delete Menu ---\n");
        printf("1. Delete from First\n");
        printf("2. Delete from Last\n");
        printf("3. Delete from Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromFirst(&head);
                break;
            case 2:
                deleteFromLast(&head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromAny(&head, pos);
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
