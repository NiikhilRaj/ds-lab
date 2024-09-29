#include <stdio.h>

#define MAX_DEGREE 20

typedef struct polynomial {
    int exp;
    int coeff[MAX_DEGREE];
} pol;

pol addPol(pol p1, pol p2);

int main() {
    pol p1, p2, p3;
    
    int e;
    printf("Enter the maximum degree of the polynomials: ");
    scanf("%d", &e);

    p1.exp = p2.exp = e;
    
    for (int i = 0; i <= p1.exp; i++) {
        p1.coeff[i] = 0;
        p2.coeff[i] = 0;
    }

    printf("Enter the coefficients in ascending order of degree for polynomial 1:\n");
    for (int i = 0; i <= p1.exp; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &p1.coeff[i]);
    }

    printf("Enter the coefficients in ascending order of degree for polynomial 2:\n");
    for (int i = 0; i <= p2.exp; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &p2.coeff[i]);
    }
    
    p3 = addPol(p1, p2);

    printf("Resultant Polynomial: ");
    int first = 1;
    for (int i = 0; i <= p3.exp; i++) {
        if (p3.coeff[i] != 0) {
            if (!first) {
                printf(" + ");
            }
            printf("%dx^%d", p3.coeff[i], i);
            first = 0;
        }
    }
    if (first) {
        printf("0");
    }
    printf("\n");

    return 0;
}

pol addPol(pol p1, pol p2) {
    pol result;
    result.exp = p1.exp;

    for (int i = 0; i <= result.exp; i++) {
        result.coeff[i] = 0;
    }

    for (int i = 0; i <= result.exp; i++) {
        result.coeff[i] = p1.coeff[i] + p2.coeff[i];
    }
    
    return result;
}
