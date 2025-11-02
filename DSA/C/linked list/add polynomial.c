/*
 * 4. Write a C program to perform addition of two polynomials 
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

// Function to add two polynomials
struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* resultHead = NULL;
    struct PolyNode* resultTail = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        struct PolyNode* term = NULL;

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exp > poly2->exp) {
                term = (struct PolyNode*)malloc(sizeof(struct PolyNode));
                term->coeff = poly1->coeff;
                term->exp = poly1->exp;
                poly1 = poly1->next;
            } else if (poly1->exp < poly2->exp) {
                term = (struct PolyNode*)malloc(sizeof(struct PolyNode));
                term->coeff = poly2->coeff;
                term->exp = poly2->exp;
                poly2 = poly2->next;
            } else { // Exponents are equal
                int sumCoeff = poly1->coeff + poly2->coeff;
                if (sumCoeff != 0) { // Only add if sum is not zero
                    term = (struct PolyNode*)malloc(sizeof(struct PolyNode));
                    term->coeff = sumCoeff;
                    term->exp = poly1->exp;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            term = (struct PolyNode*)malloc(sizeof(struct PolyNode));
            term->coeff = poly1->coeff;
            term->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly2 != NULL) {
            term = (struct PolyNode*)malloc(sizeof(struct PolyNode));
            term->coeff = poly2->coeff;
            term->exp = poly2->exp;
            poly2 = poly2->next;
        }

        if (term != NULL) {
            term->next = NULL;
            if (resultHead == NULL) {
                resultHead = resultTail = term;
            } else {
                resultTail->next = term;
                resultTail = term;
            }
        }
    }
    return resultHead;
}

// --- Helper Functions (for setup and display) ---

// Function to insert a term (assumes terms are added in sorted order)
void insertTerm(struct PolyNode **head, int coeff, int exp) {
    struct PolyNode *newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct PolyNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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

// Main function to test polynomial addition
int main() {
    struct PolyNode *poly1 = NULL;
    struct PolyNode *poly2 = NULL;
    
    // Create poly1: 5x^2 + 4x^1 + 2x^0
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);
    printf("Polynomial 1: ");
    displayPoly(poly1);

    // Create poly2: -3x^2 - 3x^1 + 5x^0
    insertTerm(&poly2, -3, 2);
    insertTerm(&poly2, -3, 1);
    insertTerm(&poly2, 5, 0);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    printf("\nAdding polynomials...\n");
    struct PolyNode *result = addPolynomials(poly1, poly2);

    printf("Result: ");
    displayPoly(result); // Expected: 2x^2 + 1x^1 + 7x^0

    freePoly(&poly1);
    freePoly(&poly2);
    freePoly(&result);
    return 0;
}
