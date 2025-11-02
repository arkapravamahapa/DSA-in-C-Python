/*
 * 1. Write a C program to create a Double linked list along with
 * all specified insert, delete, search, count, and display
 * functions.
 * (Create a menu bar using switch case statement in the main)
 * Mention the necessary algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

/*
 * --- Algorithm: createNode ---
 * 1. Allocate memory for a new node.
 * 2. Set the node's data to the given value.
 * 3. Set both prev and next pointers to NULL.
 * 4. Return the new node.
 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*
 * --- Algorithm: displayList (a) ---
 * 1. Check if the list is empty (head == NULL). If so, print "Empty" and return.
 * 2. Create a temporary pointer 'temp' and start it at 'head'.
 * 3. Print "Head <-> " to indicate the start.
 * 4. Loop while 'temp' is not NULL:
 * a. Print the 'temp->data'.
 * b. Move 'temp' to 'temp->next'.
 * 5. Print "NULL" to indicate the end of the list.
 */
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List (Head to Tail): Head <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*
 * --- Algorithm: insertAtFirst (b) ---
 * 1. Create a new node with the given data.
 * 2. Check if the list is empty (head == NULL).
 * 3. If empty, set 'head' to the new node.
 * 4. If not empty:
 * a. Set new node's 'next' to the current 'head'.
 * b. Set the current 'head's 'prev' to the new node.
 * c. Update 'head' to point to the new node.
 */
void insertAtFirst(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", data);
}

/*
 * --- Algorithm: insertAtLast (c) ---
 * 1. Create a new node with the given data.
 * 2. Check if the list is empty (head == NULL).
 * 3. If empty, set 'head' to the new node.
 * 4. If not empty:
 * a. Create a 'temp' pointer and start it at 'head'.
 * b. Traverse to the end of the list (while temp->next != NULL).
 * c. Set the last node's 'next' to the new node.
 * d. Set the new node's 'prev' to 'temp' (the last node).
 */
void insertAtLast(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", data);
}

/*
 * --- Algorithm: insertAtAny (d) ---
 * 1. Check if the position is 1. If so, call 'insertAtFirst' and return.
 * 2. Create a 'temp' pointer at 'head' and a counter 'i' at 1.
 * 3. Traverse the list until 'i' is 'pos - 1' or 'temp' is NULL.
 * 4. If 'temp' is NULL, the position is out of bounds. Print error.
 * 5. If 'temp->next' is NULL (at the last node), call 'insertAtLast' and return.
 * 6. If in the middle:
 * a. Create a new node.
 * b. Set new node's 'next' to 'temp->next'.
 * c. Set new node's 'prev' to 'temp'.
 * d. Set 'temp->next's 'prev' to the new node.
 * e. Set 'temp->next' to the new node.
 */
void insertAtAny(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtFirst(data);
        return;
    }

    struct Node* temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", pos);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) { // Not inserting at the very end
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, pos);
}

/*
 * --- Algorithm: searchElement (e) ---
 * 1. Check if the list is empty. If so, print "Not found" and return.
 * 2. Create a 'temp' pointer at 'head' and a 'pos' counter at 1.
 * 3. Loop while 'temp' is not NULL:
 * a. If 'temp->data' matches the key, print "Found at position 'pos'" and return.
 * b. Move 'temp' to 'temp->next' and increment 'pos'.
 * 4. If the loop finishes, print "Element not found".
 */
void searchElement(int key) {
    if (head == NULL) {
        printf("List is empty. Element not found.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

/*
 * --- Algorithm: countNodes (f) ---
 * 1. Initialize a 'count' variable to 0.
 * 2. Create a 'temp' pointer and start it at 'head'.
 * 3. Loop while 'temp' is not NULL:
 * a. Increment 'count'.
 * b. Move 'temp' to 'temp->next'.
 * 4. Print the final 'count'.
 */
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

/*
 * --- Algorithm: deleteFromFirst (g) ---
 * 1. Check if the list is empty (head == NULL). If so, print error.
 * 2. Create a 'temp' pointer to 'head'.
 * 3. If the list has only one node (head->next == NULL), set 'head' to NULL.
 * 4. If the list has more than one node:
 * a. Move 'head' to 'head->next'.
 * b. Set the new 'head's 'prev' to NULL.
 * 5. Free the 'temp' node and print confirmation.
 */
void deleteFromFirst() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    int data = head->data;
    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    printf("%d deleted from the beginning.\n", data);
}

/*
 * --- Algorithm: deleteFromLast (h) ---
 * 1. Check if the list is empty. If so, print error.
 * 2. Create a 'temp' pointer to 'head'.
 * 3. If the list has only one node (head->next == NULL), call 'deleteFromFirst'.
 * 4. If the list has more than one node:
 * a. Traverse 'temp' to the last node (while temp->next != NULL).
 * b. Set the 'prev' node's 'next' to NULL (temp->prev->next = NULL).
 * c. Free 'temp' and print confirmation.
 */
void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == NULL) {
        deleteFromFirst();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int data = temp->data;
    temp->prev->next = NULL;
    free(temp);
    printf("%d deleted from the end.\n", data);
}

/*
 * --- Algorithm: deleteFromAny (i) ---
 * 1. Check if the list is empty. If so, print error.
 * 2. If 'pos' is 1, call 'deleteFromFirst' and return.
 * 3. Create a 'temp' pointer at 'head' and counter 'i' at 1.
 * 4. Traverse to the 'pos'-th node (loop until i < pos or temp is NULL).
 * 5. If 'temp' is NULL, position is out of bounds. Print error.
 * 6. If 'temp' is the last node (temp->next == NULL), call 'deleteFromLast'.
 * 7. If in the middle:
 * a. Link 'temp's 'prev' node to 'temp's 'next' node.
 * b. Link 'temp's 'next' node to 'temp's 'prev' node.
 * c. Free 'temp' and print confirmation.
 */
void deleteFromAny(int pos) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteFromFirst();
        return;
    }

    struct Node* temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", pos);
        return;
    }

    if (temp->next == NULL) { // Deleting the last node
        deleteFromLast();
    } else { // Deleting from the middle
        int data = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("%d deleted from position %d.\n", data, pos);
    }
}

// Main function with switch-case menu
int main() {
    int choice, data, pos, key;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf(" 1. Display List (a)\n");
        printf(" 2. Insert at First (b)\n");
        printf(" 3. Insert at Last (c)\n");
        printf(" 4. Insert at Any Position (d)\n");
        printf(" 5. Search Element (e)\n");
        printf(" 6. Count Nodes (f)\n");
        printf(" 7. Delete from First (g)\n");
        printf(" 8. Delete from Last (h)\n");
        printf(" 9. Delete from Any Position (i)\n");
        printf(" 0. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            choice = -1; // Set to invalid
        }

        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(data);
                break;
            case 3:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtAny(data, pos);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(key);
                break;
            case 6:
                countNodes();
                break;
            case 7:
                deleteFromFirst();
                break;
            case 8:
                deleteFromLast();
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromAny(pos);
                break;
            case 0:
                printf("Exiting program. Freeing list...\n");
                while (head != NULL) {
                    deleteFromFirst(); // Free all nodes
                }
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 0 and 9.\n");
        }
    }
    return 0;
}
