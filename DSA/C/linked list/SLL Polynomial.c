/*
 * 4. Write a C program to store polynomial using linked list.
 * Store the term in ascending order (of exponent).
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
};

// Function to insert a term into the polynomial
// This function inserts in ascending order of exponent
// and combines terms with the same exponent.
void insertTerm(struct PolyNode **head, int coeff, int exp) {
    struct PolyNode *newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    struct PolyNode *temp = *head;
    struct PolyNode *prev = NULL;

    // Traverse to find the correct position
    while (temp != NULL && temp->exp < exp) {
        prev = temp;
        temp = temp->next;
    }

    // Case 1: Exponent already exists
    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
        free(newNode); // Don't need the new node
        // If coeff becomes 0, we could delete the node, but
        // for simplicity, we'll keep it (e.g., 5x^2 - 5x^2 = 0x^2)
    }
    // Case 2: Insert at the beginning
    else if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    }
    // Case 3: Insert in the middle or at the end
    else {
        newNode->next = temp;
        prev->next = newNode;
    }
}

// Function to display the polynomial
void displayPoly(struct PolyNode *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct PolyNode *temp = head;
    printf("Polynomial: ");
    while (temp != NULL) {
        // Print coefficient and 'x'
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the polynomial list
void freePoly(struct PolyNode **head) {
    struct PolyNode *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function to test polynomial representation
int main() {
    struct PolyNode *poly = NULL;
    int choice, coeff, exp;

    while (1) {
        printf("\n--- Polynomial Menu ---\n");
        printf("1. Add Term (in ascending order)\n");
        printf("2. Display Polynomial\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient: ");
                scanf("%d", &coeff);
                printf("Enter exponent: ");
                scanf("%d", &exp);
                if (exp < 0) {
                    printf("Exponent must be non-negative.\n");
                    break;
                }
                insertTerm(&poly, coeff, exp);
                break;
            case 2:
                displayPoly(poly);
                break;
            case 3:
                printf("Exiting... Freeing polynomial.\n");
                freePoly(&poly);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
