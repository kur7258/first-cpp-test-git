#include <stdio.h>
#include<math.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct 
{
    int degree; //차수
    float coef[MAX_DEGREE]; //계수
    
}polynomial;

double evaluation(polynomial,double x);
void Addpoly(polynomial, polynomial);
void Multpoly(polynomial, polynomial);
void Addterm(polynomial, polynomial);
void Delterm(polynomial, polynomial);
void Multerm(polynomial, polynomial);


int main()
{
    double x; //미지수
    int i, k;
    int menu = 0;
    polynomial A = { {0},{1} };
    polynomial B = { {0},{1} };
    printf("A의 차수 :");
    scanf_s("%d", &A.degree);
    printf("A 항의 계수\n");

    for (i = 0; i <= A.degree; i++)
    {
        printf("A의 %d번째 항:", i + 1);
        scanf_s("%f", &A.coef[i]);
    }

    printf("B의 차수 :");
    scanf_s("%d", &B.degree);
    printf("B의 항의 계수\n");

    for (i = 0; i <= B.degree; i++)
    {
        printf("B의 %d번째 항:", i + 1);
        scanf_s("%f", &B.coef[i]);
    }


    printf("1.addPoly\n");
    Addpoly(A, B);

    printf("2.multPoly\n");
    Multpoly(A, B);

    printf("3.addTerm\n");
    Addterm(A, B);

    printf("4.delTerm\n");
    Delterm(A, B);

    printf("5.multTerm\n");
    Multerm(A, B);

    printf("6.evaluation\n");
    printf("미지수 x 값 입력 : ");
    scanf_s("%lf", &x);
    printf("다항식의 값 = %lf", evaluation(A, x));


}
polynomial addpoly(polynomial A, polynomial B) 
{
    polynomial C;
    int A_index = 0;
    int B_index = 0;
    int C_index = 0;

    int A_degree = A.degree;
    int B_degree = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while (A_index <= A.degree && B_index <= B.degree) 
    {
        if (A_degree > B_degree) 
        {
            C.coef[C_index++] = A.coef[A_index++];
            A_degree--;
        }

        else if (A_degree == B_degree) 
        {
            C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
            A_degree--;
            B_degree--;
        }
        else 
        {
            C.coef[C_index++] = B.coef[B_index++];
            B_degree--;

        }
    }
    return C;


}

polynomial multpoly(polynomial A, polynomial B) 
{
    polynomial D;
    int i, menu, d = 0;
    int A_degree = A.degree;
    int B_degree = B.degree;
    D.degree = A.degree + B.degree;
    for (i = 0; i < D.degree + 1; ++i)
    {
        D.coef[i] = 0;
    }
    for (i = 0; i < A.degree + 1; ++i) 
    {
        for (menu = 0; menu < B.degree + 1; ++menu)
        {
            D.coef[i + menu] = D.coef[i + menu] + A.coef[i] * B.coef[menu];
        }
    }
    return D;

}


polynomial addterm(polynomial A, polynomial E)
{
    polynomial F;
    int A_index = 0;
    int E_index = 0;
    int F_index = 0;

    int A_degree = A.degree;
    int E_degree = E.degree;
    F.degree = MAX(A.degree, E.degree);

    while (A_index <= A.degree && E_index <= E.degree) 
    {
        if (A_degree > E_degree)
        {
            F.coef[F_index++] = A.coef[A_index++];
            A_degree--;
        }

        else if (A_degree == E_degree) 
        {
            F.coef[F_index++] = A.coef[A_index++] + E.coef[E_index++];
            A_degree--;
            E_degree--;
        }
        else 
        {
            F.coef[F_index++] = E.coef[E_index++];
            E_degree--;

        }
    }
    return F;
}


void printPoly(polynomial P) 
{
    int a;
    int degree;
    degree = P.degree;
    for (a = 0; a <= P.degree; a++)
    {
        if (P.coef[a] == 0)
        {
            degree--;
            continue;
        }
        printf("%3.0fx^%d", P.coef[a], degree--);
    }
    printf("\n");

}


void Addpoly(polynomial A, polynomial B) 
{
    polynomial C;
    C = addpoly(A, B);
    printf("\n A(x)=");
    printPoly(A);
    printf("\n B(x)=");
    printPoly(B);
    printf("\n C(x)=");
    printPoly(C);

}

void Multpoly(polynomial A, polynomial B) 
{

    polynomial D;
    D = multpoly(A, B);
    printf("\n A(x)=");
    printPoly(A);
    printf("\n B(x)=");
    printPoly(B);
    printf("\n D(x)=");
    printPoly(D);
}
void Addterm(polynomial A, polynomial B) 
{
    printf("1) A값에 항을 추가합니다.\n ");
    int a;
    int b;

    polynomial P;
    polynomial Q;

    printf("\n A(x)=");
    printPoly(A);

    while (1) 
    {

        printf("추가 항 차수 입력\n");
        scanf_s("%d", &P.degree);
        if (P.degree > A.degree) 
        {
            for (b = 0; b <= P.degree; b++)
            {
                P.coef[b] = 0;
            }
            printf("추가 항 계수 입력 :");
            scanf_s("%f", &P.coef[0]);
            Q = addterm(A, P);
            A = Q;
            printf("\n A(x)=");
            printPoly(A);
            break; 
        }
        if (A.degree == P.degree && A.coef[0] != 0)
        {
            printf("\n A(x)=");
            printPoly(A);
            break;
        }
        else if (A.coef[P.degree - A.degree] == 0)
        {
            printf("\n A(x)=");
            printPoly(A);
            break;
        }
        else if (A.coef[A.degree - P.degree] != 0)
        {
            printf("\n A(x)=");
            printPoly(A);
            break;
        }
        else
        {
            for (b = 0; b <= P.degree; b++) 
            {
                P.coef[b] = 0;
            }
            printf("추가 항 계수 입력 :");
            scanf_s("%f", &P.coef[0]);
            Q = addterm(A, P);
            A = Q;
            printf("\n A(x)=");
            printPoly(A);
        }
    }

}
void Delterm(polynomial A, polynomial B) 
{
    int a;
    int b;

    polynomial E;
    polynomial F;
    printf("\n A(x)=");

    printPoly(A);
    polynomial G;

    while (1) 
    {

        printf("삭제 차수 입력 :\n");
        scanf_s("%d", &G.degree);
        if (G.degree > A.degree || A.coef[A.degree - G.degree] == 0)
        {
            printf("삭제할 차수가 없습니다.\n");
            continue;
        }
        for (b = 0; b <= G.degree; b++) 
        {
            E.coef[b] = 0;
        }
        (A.coef[A.degree - G.degree]) = 0;
        printf("\n A(x)=");
        printPoly(A);
        break;
    }

}
void Multerm(polynomial A, polynomial B) 
{

    int b;

    printf("\n A(x)=");

    printPoly(A);
    polynomial H;
    polynomial I;

    while (1) 
    {

        printf("곱할 차수 : \n");
        scanf_s("%d", &H.degree);

        for (b = 0; b <= H.degree; b++) 
        {
            H.coef[b] = 0;
        }
        printf("항의 계수 : \n");
        scanf_s("%f", &H.coef[0]);

        I = multpoly(A, H);
        A = I;
        printf("\n A(x)=");
        printPoly(A);
        break;
    }

}

double evaluation(polynomial A,double x)
{
    double result = 0;
    int i,k,l;
    double exp[MAX_DEGREE];
    double coef[MAX_DEGREE];

    printf("입력된 다항식의 지수 차례대로 입력\n");
    for (k = 0; k <= A.degree; k++)
    {
        printf("%d번째 지수 : ",k + 1);
        scanf_s("%lf", &exp[k]);
    }

    printf("입력된 다항식의 계수 차례대로 입력\n");
    for (k = 0; k <= A.degree; k++)
    {
        printf("%d번째 계수 : ", k + 1);
        scanf_s("%lf", &coef[k]);
    }

   


    for (i = 0; i <= A.degree; i++)
    {
        if (exp[i]!=0)
        {
            result += coef[i] * pow(x, exp[i]);
        }
        else
        {
            result += coef[i];
        }
       
    }
    return result;
}