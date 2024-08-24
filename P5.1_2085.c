#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
    int coeff;
    int exp;
    struct polynomial *next;
}poly;

poly *addPoly(poly *pol1, poly *pol2);
poly *create(int exponent, int coefficient);
poly *createPolynomial(int n);
void displayPolynomial(poly *start);

void main()
{
    int n1, n2;
    poly *p1, *p2, *sum;

    printf("Polynomial 1\nEnter the maximum power: ");
    scanf("%d", &n1);
    p1=createPolynomial(n1);

    printf("Polynomial 1\nEnter the maximum power: ");
    scanf("%d", &n2);
    p2=createPolynomial(n2);

    sum= addPoly(p1, p2);

    printf("Polynomial 1: ");
    displayPolynomial(p1);

    printf("Polynomial 2: ");
    displayPolynomial(p2);
    
    printf("New polynomial: ");
    displayPolynomial(sum);
}

poly *create(exponent, coefficient){
    poly *new=(poly *)malloc(sizeof(poly));
    new->exp=exponent;
    new->coeff=coefficient;
    new->next=NULL;
    return new;
};

poly *createPolynomial(int n){
    poly *new, *temp, *start=NULL;
    int c;
    if (n==0)
    {
        return NULL;
    }
    else
    {
        for (int i = n; i >= 0; i--)
        {
            new->exp=i;
            printf("Enter data of exponent %d: ", i);
            scanf("%d", &c);
            new = create(i, c);

            if (start==NULL)
            {
                start=new;
                temp=new;
            }
            else
            {
                temp->next=new;
                temp=new;
            }
        }
        temp->next=NULL;
    }
    return start;
};

poly *addPoly(poly *pol1, poly *pol2){
    poly *temp, *result=NULL, *new;

    while (pol1!=NULL && pol2!= NULL)
    {
        if (pol1->exp==pol2->exp)
        {
            new = create(pol1->exp, pol1->coeff+pol2->coeff);
            pol1=pol1->next;
            pol2=pol2->next;
        }
        else if (pol1->exp<pol2->exp)
        {
            new = create(pol1->exp, pol1->coeff);
            pol1=pol1->next;
        }
        else if (pol1->exp>pol2->exp)
        {
            new = create(pol2->exp, pol2->coeff);
            pol2=pol2->next;
        }

        if (result==NULL)
            {
                result=new;
                temp=new;
            }
            else
            {
                temp->next=new;
                temp=new;
            }
    }
    while (pol1!=NULL)
    {
        new = create(pol1->exp, pol1->coeff);
        temp->next=new;
        temp=new;
        pol1=pol1->next;
    }
    while (pol2=NULL)
    {
        new = create(pol2->exp, pol2->coeff);
        temp->next=new;
        temp=new;
        pol2=pol2->next;
    }
    if (temp!=NULL)
    {
        temp->next=NULL;
    }
        
    return result;
};
