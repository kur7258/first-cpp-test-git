#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {                    // ����ü polynomial ����
	int degree;                // ���׽��� ������ ������ ����
	float coef[MAX_DEGREE];  // ���׽��� �� ���� ����� ������ 1���� �迭
} polynomial;
polynomial addPoly(polynomial, polynomial);
polynomial delTerm(polynomial, int e);
void printPoly(polynomial);

void main() {
	polynomial A = { 7, {8,0,-3,0,0,7,0,8} };    // ���׽� A�� �ʱ�ȭ
	polynomial B = { 7, {-8,0,3,4,0,0,5,4} };    // ���׽� B�� �ʱ�ȭ

	polynomial C;
	polynomial D;
	C = addPoly(A, B);   // ���׽� A, B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ�� 
	D = delTerm(A, 5);  // del
	printf("\n C(x) = ");  printPoly(C);// ���׽� C ���
	printf("\n D(x) = ");  printPoly(D);
	
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;  // ���׽� ������ ��� ���׽��� ������ polynomial ����ü ���� ����
	int sum;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			sum = A.coef[A_index++] + B.coef[B_index++];
			if (sum == 0 && C_index == 0) {
				for (int i = 0;i <= C.degree;i++)
				{
					A.coef[i] = 0;
					B.coef[i] = 0;
					C.coef[i] = 0;
				}
				printf("0�� �ȵ˴ϴ�.\n");
				break;
			}
			else {
				C.coef[C_index++] = sum;
			}
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;    // ���׽� ������ ��� ���׽� C�� ��ȯ
}

polynomial delTerm(polynomial P, int e)
{
	polynomial Q;
	Q = P;
	int P_degree = P.degree;
	int i = 0;

	Q.degree = P.degree;

	for (i = 0; i <= P.degree; i++)
	{
		if (P_degree == e)
		{
			Q.coef[i] = 0;
		}
		else
		{
			Q.coef[i] = P.coef[i];
		}
		P_degree--;
	}

	return Q;
}


void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}
