#include <stdio.h>
#include <math.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {             // ����ü polynomial ����
	int degree;              // ���׽��� ������ ������ ����
	float coef[MAX_DEGREE];  // ���׽��� �� ���� ����� ������ 1���� �迭
} polynomial;

polynomial addTerm(polynomial P , float coef, int exp);
void delTerm(polynomial *P, int exp);
polynomial multTerm(polynomial P, float coef, int exp);
polynomial addPoly(polynomial, polynomial);
float evaluation(polynomial P, float t);
void printPoly(polynomial);

void main() {
	polynomial X = { 5,{ 4, 0, 0, 8, 0, 3}};    // ���׽� P�� �ʱ�ȭ
	polynomial P = X;    // ���׽� P�� �ʱ�ȭ
	polynomial A = { 5, {-7, 8,0,0,4,5}}; 
	polynomial B = { 5, {7,4,0,1,1,4}}; 
	polynomial C;
	polynomial Q;  // ���׽� B�� �ʱ�ȭ
	float eval;

    Q = addTerm(P, -4, 3);
    
    printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
    printf("\n Q = addTerm(P, -4, 3)\n");
	printf("\n Q(x) =");  printPoly(Q);   // ���׽� Q ���
	printf("\n");
	
	Q = addTerm(P, 9, 2);
    
    printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
    printf("\n Q = addTerm(P, 9, 2)\n");
	printf("\n Q(x) =");  printPoly(Q);   // ���׽� Q ���
	printf("\n");
	
	Q = addTerm(P, 8, 7);
    
    printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
    printf("\n Q = addTerm(P, 8, 7)\n");
	printf("\n Q(x) =");  printPoly(Q);   // ���׽� Q ���
	printf("\n");
	
	
	printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
  	delTerm(&P, 2);
  	printf("\n delTerm(&P, 2)\n");
	printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
	printf("\n");
	
	P = X;
	printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
  	delTerm(&P, 5);
  	printf("\n delTerm(&P, 5)\n");
	printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
	printf("\n");
	
	P = X;	
	Q = multTerm(P, 2, 4);
	printf("\n P(x) =");  printPoly(P);   // ���׽� P ���
	printf("\n multTerm(P, 2, 4)\n");
	printf("\n Q(x) =");  printPoly(Q);   // ���׽� Q ���
	printf("\n\n");
	
	C = addPoly(A, B);   // ���׽� A, B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ�� 
	printf(" C = A + B \n");
	printf("\n A(x) =");  printPoly(A);   // ���׽� A ���
	printf("\n B(x) =");  printPoly(B);   // ���׽� B ���
	printf("\n C(x) =");  printPoly(C);   // ���׽� C ���
	printf("\n\n");
	
	printf("\n C(x) =");  printPoly(C);   // ���׽� C ���
	eval = evaluation(C, 2.0);
	printf("\n C(2.0) = %f", eval);
	
	getchar();
}

polynomial addTerm(polynomial P , float coef, int exp){
	 int index, degree;
	 polynomial Q;
	 int i;
	 
	 degree = P.degree;
	 index = P.degree - exp;   // ���� exp�� ���� �ε���  
	 if(exp<=degree)          // �߰��� ������ �ְ��� ���� �۰ų� ���� ��� 
	   if(P.coef[index]!=0) return P;  // 0�� �ƴ� ���� �ִ� ��� 
	   else {
	         P.coef[index] = coef;    // 0�� ��� 
	        return P;
	    }
	 if(exp>degree) {        // ���� exp�� �ְ��� ���� ū ��� 
	 	index = exp-degree;   
	 	Q.degree = exp;       // Q�� �ְ����� exp�� ����� coef�� ���� 
	 	Q.coef[0]=coef;
		for(i=1; i<index;i++) Q.coef[i] = 0;   // coef�� 1������ (exp - P�� �ְ�����)-1 ���� ��� 0����  
		for(i=0; i<=degree;i++) Q.coef[index++]= P.coef[i];  // P�� ������� Q�� �̵���Ŵ.  Q�� return 
		return Q;
	}
}

void delTerm(polynomial *P, int exp){
	int i, count, degree, index;
	
	degree = P->degree;
	index = P->degree -exp;
		
	if(exp<degree) P->coef[index] = 0;  // exp�� P�� �ְ����� ���� ���� ���� �ش� ����� 0���� ��.  
	if(exp==degree) {                   // �ְ����� �����ϴ� ��� 
	      P->coef[0] = 0;               // �ְ����� ����� 0���� ��. 
	      count=0; 
		  for(i=0; P->coef[i]==0; i++)  // �ְ������� ��� �����ؼ� 0�ΰ��� ������. �� ������ count�� ���� 
		     count++;
		  if(count>degree) {            // ���  0�� ��� ó���� ���� 
		  	   P->degree = 0; P->coef[0] = 0;
		  	   return;
		  }  
		  for(i=0; i<degree-count+1; i++)  // �տ� 0�� �κ��� ���ֱ� ���� �޺κ��� ������ �̵�  
		     P->coef[i] = P->coef[i+count];
		  P->degree=degree-count;          // P�� �ְ����� ������. 
	}
}
		     
polynomial multTerm(polynomial P, float coef, int exp){

	int i, degree, q_degree;
	polynomial Q;
	
	degree = P.degree;
	q_degree = degree + exp;   
	Q.degree = q_degree;     // Q�� �ְ����� ���� 
	
	for(i=0; i<=degree; i++)   // Q�� ������� P�� ��� * coef�� ����. 
		Q.coef[i] = P.coef[i]*coef;
	for(i=degree+1; i<=q_degree; i++)   // Q�� �ںκ��� 0���� ä��. 
		Q.coef[i]=0;
		
	return Q;
}
	
	
	
	
polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;   // ���׽� ������ ��� ���׽��� ������ polynomial ����ü ���� ����
	int i, count, degree;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	
	degree = C.degree;     // �ְ����� ����� 0�� ��츦 �ذ��ϱ� ���� delTerm( )���� �� ��İ� ���� ó����. 
    count=0; 
    for(i=0; C.coef[i]==0; i++)
	     count++;
	if(count>degree) {
	   C.degree = 0; C.coef[0] = 0;
	   return C;
	}    
	for(i=0; i<degree-count+1; i++)
	     C.coef[i] = C.coef[i+count];
	C.degree=degree-count;
		
	return C;    // ���׽� ������ ��� ���׽� C�� ��ȯ
}

float evaluation(polynomial P, float t){
	float sum;
	int i;
	int degree;
	
	degree = P.degree;
	sum = 0.0;
	for(i=0; i<=degree; i++)
	  sum = sum + P.coef[i]*pow(t, degree-i);
	
	return sum;
}
	  
void printPoly(polynomial P) {   // ����� 0�� ��� ����� ���� �ʱ� ���� ������ �Լ�. 
	int i, degree;
	degree = P.degree;

	if(P.degree==0 && P.coef[0]==0) { printf("\n\n 0 \n"); return;} 
	printf("%3.0fx^%d", P.coef[0], degree--);
	for (i = 1; i <= P.degree; i++) {
		if(P.coef[i] != 0) printf(" + %3.0fx^%d", P.coef[i], degree);
		degree--;
	}
	printf("\n");
}

/*void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}*/


