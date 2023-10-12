#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term with the given coefficient and exponent
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(Term** polynomial, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        Term* current = *polynomial;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(Term* polynomial) {
    while (polynomial != NULL) {
        printf("%dx^%d ", polynomial->coefficient, polynomial->exponent);
        polynomial = polynomial->next;
        if (polynomial != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to evaluate a polynomial for a given value of x
int evaluatePolynomial(Term* polynomial, int x) {
    int result = 0;
    while (polynomial != NULL) {
        result += polynomial->coefficient * pow(x, polynomial->exponent);
        polynomial = polynomial->next;
    }
    return result;
}

int main() {
    Term* polynomial = NULL;
    int choice, coefficient, exponent, x;

    do {
        printf("\nPolynomial Operations Menu:\n");
        printf("1. Add Term\n");
        printf("2. Display Polynomial\n");
        printf("3. Evaluate Polynomial\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                addTerm(&polynomial, coefficient, exponent);
                break;
            case 2:
                printf("Polynomial: ");
                displayPolynomial(polynomial);
                break;
            case 3:
                printf("Enter the value of x: ");
                scanf("%d", &x);
                printf("Result: %d\n", evaluatePolynomial(polynomial, x));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free memory used for the polynomial
    while (polynomial != NULL) {
        Term* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}

