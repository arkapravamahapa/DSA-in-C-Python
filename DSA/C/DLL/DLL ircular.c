/*
 * 3. Write a C program to create a Double Circular linked list
 * along with all specified insert, delete, search, count, and
 * display functions.
 * (Create a menu bar using switch case statement in the main)
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

// Helper function to create a new node
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
 * 1. Check if the list is empty (head == NULL). If so, print "Empty".
 * 2. Create 'temp' pointer and start it at 'head'.
 * 3. Use a do-while loop to ensure at least one node prints.
 * 4. Inside loop: print 'temp->data' and move 'temp' to 'temp->next'.
 * 5. Loop condition: while (temp != head).
 */
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List (Circular): Head <-> ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Head (loop)\n");
}

/*
 * --- Algorithm: insertAtFirst (b) ---
 * 1. Create a new node.
 * 2. If list is empty (head == NULL):
 * a. Set 'head' to new node.
 * b. Make new node point to itself: next = head, prev = head.
 * 3. If list is not empty:
 * a. Find the last node (which is head->prev).
 * b. Set new node's 'next' to 'head'.
 * c. Set new node's 'prev' to 'last'.
 * d. Set 'last's 'next' to new node.
 * e. Set 'head's 'prev' to new node.
 * f. Update 'head' to point to the new node.
 */
void insertAtFirst(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode; // Update head
    }
    printf("%d inserted at the beginning.\n", data);
}

/*
 * --- Algorithm: insertAtLast (c) ---
 * 1. Create a new node.
 * 2. If list is empty, call 'insertAtFirst' (it handles this case).
 * 3. If list is not empty:
 * a. Find the last node (head->prev).
 * b. Set new node's 'next' to 'head'.
 * c. Set new node's 'prev' to 'last'.
 * d. Set 'last's 'next' to new node.
 * e. Set 'head's 'prev' to new node.
 * (Note: Do not update 'head' pointer)
 */
void insertAtLast(int data) {
    if (head == NULL) {
        insertAtFirst(data); // Handles empty list case
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* last = head->prev;
    
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    printf("%d inserted at the end.\n", data);
}

/*
 * --- Algorithm: insertAtAny (d) ---
 * 1. If 'pos' < 1, print error.
 * 2. If 'pos' == 1, call 'insertAtFirst'.
 * 3. Traverse to the (pos - 1)-th node ('temp').
 * 4. If 'temp' loops back to 'head' before pos-1, check if it's the last node.
 * a. If 'i == pos - 1' and 'temp->next == head', call 'insertAtLast'.
 * b. Otherwise, position is out of bounds.
 * 5. If inserting in the middle:
 * a. Create new node.
 * b. Link new node: next = temp->next, prev = temp.
 * c. Link surrounding nodes: temp->next->prev = newNode, temp->next = newNode.
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
    // Traverse to (pos-1)th node
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) { // We looped around
            printf("Position %d is out of bounds.\n", pos);
            return;
        }
    }

    // 'temp' is now at (pos-1)th node
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, pos);
}

/*
 * --- Algorithm: searchElement (e) ---
 * 1. If list is empty, print "Not found".
 * 2. Create 'temp' at 'head' and 'pos' counter at 1.
 * 3. Use a do-while loop:
 * a. If 'temp->data' == key, print "Found" and return.
 * b. Move 'temp' to 'temp->next', increment 'pos'.
 * 4. Loop condition: while (temp != head).
 * 5. If loop finishes, print "Not found".
 */
void searchElement(int key) {
    if (head == NULL) {
        printf("List is empty. Element not found.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    
    printf("Element %d not found in the list.\n", key);
}

/*
 * --- Algorithm: countNodes (f) ---
 * 1. If list is empty, print 0.
 * 2. Initialize 'count' = 0 and 'temp' = head.
 * 3. Use a do-while loop:
 * a. Increment 'count'.
 * b. Move 'temp' to 'temp->next'.
 * 4. Loop condition: while (temp != head).
 * 5. Print 'count'.
 */
void countNodes() {
    if (head == NULL) {
        printf("Total number of nodes: 0\n");
        return;
    }
    int count = 0;
    struct Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Total number of nodes: %d\n", count);
}

/*
 * --- Algorithm: deleteFromFirst (g) ---
 * 1. If list is empty, print error.
 * 2. If list has one node (head->next == head):
 * a. Free 'head', set 'head' to NULL.
 * 3. If list has more than one node:
 * a. 'last' = head->prev, 'temp' = head.
 * b. 'head' = head->next.
 * c. 'head->prev' = last.
 * d. 'last->next' = head.
 * e. Free 'temp'.
 */
void deleteFromFirst() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    int data = head->data;
    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
    printf("%d deleted from the beginning.\n", data);
}

/*
 * --- Algorithm: deleteFromLast (h) ---
 * 1. If list is empty, print error.
 * 2. If list has one node, call 'deleteFromFirst'.
 * 3. If list has more than one node:
 * a. 'last' = head->prev.
 * b. 'newLast' = last->prev.
 * c. 'newLast->next' = head.
 * d. 'head->prev' = newLast.
 * e. Free 'last'.
 */
void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == head) { // Only one node
        deleteFromFirst();
        return;
    }
    struct Node* last = head->prev;
    int data = last->data;
    struct Node* newLast = last->prev;
    
    newLast->next = head;
    head->prev = newLast;
    free(last);
    printf("%d deleted from the end.\n", data);
}

/*
 * --- Algorithm: deleteFromAny (i) ---
 * 1. If list is empty or 'pos' < 1, print error.
 * 2. If 'pos' == 1, call 'deleteFromFirst'.
 * 3. Traverse to the 'pos'-th node ('temp').
 * 4. If 'temp == head' (pos out of bounds), print error.
 * 5. If 'temp->next == head' (deleting last node), call 'deleteFromLast'.
 * 6. If in the middle:
 * a. temp->prev->next = temp->next
 * b. temp->next->prev = temp->prev
 * c. Free 'temp'.
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
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position %d is out of bounds.\n", pos);
            return;
        }
    }

    // 'temp' is now at the 'pos'-th node
    if (temp->next == head) { // Deleting the last node
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
        printf("\n--- Doubly Circular Linked List Menu ---\n");
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
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1; 
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
