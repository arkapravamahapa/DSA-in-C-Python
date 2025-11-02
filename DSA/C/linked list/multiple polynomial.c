/*
 * 7. Write a C program to perform multiplication of two polynomials 
 * using linked list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct PolyNode {
    int coeff; // Coefficient
    int exp;   // Exponent
    struct PolyNode *next;
};

// --- Helper Functions (re-used from Q4) ---

// Function to insert a term in *sorted descending order* and *combine* like terms
void insertTermSorted(struct PolyNode **head, int coeff, int exp) {
    if (coeff == 0) return; // Don't add zero terms

    struct PolyNode *newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    
    struct PolyNode *temp = *head;
    struct PolyNode *prev = NULL;

    // 1. Find the correct position
    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    // 2. Check if exponent already exists
    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
        free(newNode); // Don't need the new node
        // If combined coeff is 0, we should remove the node
        if (temp->coeff == 0) {
            if (prev == NULL) { // It's the head node
                *head = temp->next;
            } else { // It's a middle node
                prev->next = temp->next;
            }
            free(temp);
        }
    }
    // 3. Insert new node (at beginning or middle/end)
    else {
        if (prev == NULL) { // Insert at head
            newNode->next = *head;
            *head = newNode;
        } else { // Insert after prev
            newNode->next = temp;
            prev->next = newNode;
        }
    }
}

// Function to display the polynomial
void displayPoly(struct PolyNode *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct PolyNode *temp = head;
    while (temp != NULL) {
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

// --- Core Multiplication Function ---

struct PolyNode* multiplyPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;
    struct PolyNode* p1 = poly1;
    struct PolyNode* p2 = poly2;

    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    // Iterate through each term of poly1
    for (p1 = poly1; p1 != NULL; p1 = p1->next) {
        // Multiply current term of p1 with each term of poly2
        for (p2 = poly2; p2 != NULL; p2 = p2->next) {
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            
            // Insert the resulting term into the result list
            // insertTermSorted will handle sorting and combining like terms
            insertTermSorted(&result, newCoeff, newExp);
        }
    }
    return result;
}

// Main function to test polynomial multiplication
int main() {
    struct PolyNode *poly1 = NULL;
    struct PolyNode *poly2 = NULL;
    
    // Create poly1: (2x^1 + 3x^0)
    insertTermSorted(&poly1, 2, 1);
    insertTermSorted(&poly1, 3, 0);
    printf("Polynomial 1: ");
    displayPoly(poly1);

    // Create poly2: (4x^2 + 5x^1)
    insertTermSorted(&poly2, 4, 2);
    insertTermSorted(&poly2, 5, 1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    printf("\nMultiplying polynomials...\n");
    // (2x+3) * (4x^2+5x) = 8x^3 + 10x^2 + 12x^2 + 15x = 8x^3 + 22x^2 + 15x^1
    struct PolyNode *result = multiplyPolynomials(poly1, poly2);

    printf("Result: ");
    displayPoly(result); // Expected: 8x^3 + 22x^2 + 15x^1

    freePoly(&poly1);
    freePoly(&poly2);
    freePoly(&result);
    return 0;
}
