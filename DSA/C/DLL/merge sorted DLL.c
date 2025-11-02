/*
 * 2. Write a C program to merge two already sorted double list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// --- Helper Functions (for creating and displaying) ---

// Function to insert at the end (for building sorted lists)
void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Head <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/*
 * --- Algorithm: mergeSortedDLL (Iterative) ---
 * 1. Create a 'dummy' node to simplify merging. 'tail' = 'dummy'.
 * 2. While both list1 and list2 are not NULL:
 * a. Compare data at list1 and list2.
 * b. If list1->data <= list2->data:
 * i.   Attach list1 to tail: tail->next = list1
 * ii.  Set list1's prev: list1->prev = tail
 * iii. Move list1 forward: list1 = list1->next
 * c. Else (list2->data < list1->data):
 * i.   Attach list2 to tail: tail->next = list2
 * ii.  Set list2's prev: list2->prev = tail
 * iii. Move list2 forward: list2 = list2->next
 * d. Move tail forward: tail = tail->next
 * 3. After the loop, one list might have remaining nodes.
 * 4. If list1 is not NULL, attach it to tail:
 * a. tail->next = list1
 * b. list1->prev = tail
 * 5. If list2 is not NULL, attach it to tail:
 * a. tail->next = list2
 * b. list2->prev = tail
 * 6. The merged list starts at 'dummy->next'.
 * 7. Set the new head's 'prev' to NULL.
 * 8. Free the 'dummy' node.
 * 9. Return the new head.
 */
struct Node* mergeSortedDLL(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Dummy node to simplify edge cases
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->prev = NULL;
    struct Node* tail = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1->prev = tail;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2->prev = tail;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part
    if (list1 != NULL) {
        tail->next = list1;
        list1->prev = tail;
    } else if (list2 != NULL) {
        tail->next = list2;
        list2->prev = tail;
    }

    struct Node* mergedHead = dummy->next;
    mergedHead->prev = NULL; // The new head's prev should be NULL
    free(dummy);
    return mergedHead;
}

// Main function to demonstrate merging
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    // Create sorted list 1
    insertAtLast(&list1, 10);
    insertAtLast(&list1, 30);
    insertAtLast(&list1, 50);

    // Create sorted list 2
    insertAtLast(&list2, 20);
    insertAtLast(&list2, 40);
    insertAtLast(&list2, 60);

    printf("List 1:\n");
    displayList(list1);
    printf("List 2:\n");
    displayList(list2);

    printf("\nMerging lists...\n");
    mergedList = mergeSortedDLL(list1, list2);

    printf("Merged List:\n");
    displayList(mergedList);

    // Free the merged list (which contains all nodes)
    freeList(mergedList);

    return 0;
}
