#include<stdio.h>
#define MAX(a,b)((a>b)?a:b)
#define MAX_DEGREE 50
#define addTerm(p,a,e)::=if(e)

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

void main() {
    polynomial P = { 5,{4,0,0,8,0,3} };
    polynomial C;


    printf("\n P(x) = "); printPoly(P);
    printf("\n C(x) = "); printPoly(C);

    getchar();
}
polynomial addPoly(polynomial P, polynomial Q)
{
    polynomial C;
    int P_index = 0, Q_index = 0, C_index = 0;
    int P_degree = P.degree, Q_degree = Q.degree;
    C.degree = MAX(P.degree, Q.degree);

    polynomial Q = addTerm(P, a, e);


    
    return C;
}

void printPoly(polynomial P)
{
    int i, degree;
    degree = P.degree;

    for (i = 0; i <= P.degree; i++)
    {
        printf("%3.0fx^%d", P.coef[i], degree--);
        if (i < P.degree) printf("+");
    }
    printf("\n");
}