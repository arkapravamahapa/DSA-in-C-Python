/*
 * 2. Write a C program to merge two already sorted list.
 * Mention the necessary algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * --- Algorithm to Merge Two Sorted Linked Lists ---
 *
 * 1.  Create a "dummy" node. This node acts as a placeholder to simplify
 * the code, avoiding special checks for an empty result list.
 *
 * 2.  Create a `tail` pointer, initially pointing to the `dummy` node.
 * This pointer will always point to the last node in the merged list.
 *
 * 3.  Iterate while *both* list1 and list2 are not `NULL`:
 * a. Compare the data of the head nodes of `list1` and `list2`.
 * b. If `list1->data <= list2->data`:
 * i.   Attach `list1` to the `tail`: `tail->next = list1;`
 * ii.  Move `list1` one step forward: `list1 = list1->next;`
 * c. Else (`list2->data < list1->data`):
 * i.   Attach `list2` to the `tail`: `tail->next = list2;`
 * ii.  Move `list2` one step forward: `list2 = list2->next;`
 * d. Move the `tail` pointer to the node just added:
 * `tail = tail->next;`
 *
 * 4.  After the loop, one of the lists may still have nodes left.
 * Append the remaining (non-NULL) list to `tail->next`.
 * - If `list1 != NULL`, set `tail->next = list1;`
 * - If `list2 != NULL`, set `tail->next = list2;`
 *
 * 5.  The head of the new merged list is `dummy->next`.
 *
 * 6.  Free the `dummy` node.
 *
 * 7.  Return `dummy->next`.
 */

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to act as the head of the merged list
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes from either list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // The merged list starts after the dummy node
    struct Node* mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

// --- Helper Functions (for setup and display) ---

// Function to insert a node at the end
void insertAtLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Main function to demonstrate merging
int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    printf("Creating sorted list 1...\n");
    insertAtLast(&list1, 10);
    insertAtLast(&list1, 30);
    insertAtLast(&list1, 50);
    printf("List 1: ");
    displayList(list1);

    printf("\nCreating sorted list 2...\n");
    insertAtLast(&list2, 20);
    insertAtLast(&list2, 40);
    insertAtLast(&list2, 60);
    printf("List 2: ");
    displayList(list2);

    printf("\nMerging lists...\n");
    struct Node *mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    displayList(mergedList);

    // Note: We only need to free the mergedList, 
    // as it now contains all the nodes from list1 and list2.
    freeList(&mergedList);
    return 0;
}
