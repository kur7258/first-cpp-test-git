#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {                    // 구조체 polynomial 정의
	int degree;                // 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE];  // 다항식의 각 항의 계수를 저장할 1차원 배열
} polynomial;
polynomial addPoly(polynomial, polynomial);
polynomial delTerm(polynomial, int e);
void printPoly(polynomial);

void main() {
	polynomial A = { 7, {8,0,-3,0,0,7,0,8} };    // 다항식 A의 초기화
	polynomial B = { 7, {-8,0,3,4,0,0,5,4} };    // 다항식 B의 초기화

	polynomial C;
	polynomial D;
	C = addPoly(A, B);   // 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출 
	D = delTerm(A, 5);  // del
	printf("\n C(x) = ");  printPoly(C);// 다항식 C 출력
	printf("\n D(x) = ");  printPoly(D);
	
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;  // 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언
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
				printf("0은 안됩니다.\n");
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
	return C;    // 다항식 덧셈의 결과 다항식 C를 반환
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
