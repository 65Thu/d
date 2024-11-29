#include <stdio.h>
#include <stdlib.h>

// Define the structure for a term in the polynomial
struct Node {
    int coef;       // Coefficient of the term
    int expo;       // Exponent of the term
    struct Node* next; // Pointer to the next node (term)
};

// Function to create a new node
struct Node* createNode(int coef, int expo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in a sorted manner (in descending order of exponent)
void insertTerm(struct Node** poly, int coef, int expo) {
    struct Node* newNode = createNode(coef, expo);
    if (*poly == NULL || (*poly)->expo < expo) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->expo > expo) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->expo == expo) {
            temp->next->coef += coef; // Add coefficients if exponents are the same
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL && poly->coef > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo > poly2->expo) {
            insertTerm(&result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            insertTerm(&result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coef + poly2->coef, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // First polynomial: 3x^3 + 5x^2 + 6x + 4
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 6, 1);
    insertTerm(&poly1, 4, 0);
    
    // Second polynomial: 4x^3 + 2x^2 + 5x + 1
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 1, 0);

    // Print the two polynomials
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add the polynomials
    result = addPolynomials(poly1, poly2);

    // Print the result
    printf("Sum of the polynomials: ");
    printPolynomial(result);

    return 0;
}

