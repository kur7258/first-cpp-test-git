#include <stdio.h>
#include <math.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {             // 구조체 polynomial 정의
	int degree;              // 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE];  // 다항식의 각 항의 계수를 저장할 1차원 배열
} polynomial;

polynomial addTerm(polynomial P , float coef, int exp);
void delTerm(polynomial *P, int exp);
polynomial multTerm(polynomial P, float coef, int exp);
polynomial addPoly(polynomial, polynomial);
float evaluation(polynomial P, float t);
void printPoly(polynomial);

void main() {
	polynomial X = { 5,{ 4, 0, 0, 8, 0, 3}};    // 다항식 P의 초기화
	polynomial P = X;    // 다항식 P의 초기화
	polynomial A = { 5, {-7, 8,0,0,4,5}}; 
	polynomial B = { 5, {7,4,0,1,1,4}}; 
	polynomial C;
	polynomial Q;  // 다항식 B의 초기화
	float eval;

    Q = addTerm(P, -4, 3);
    
    printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
    printf("\n Q = addTerm(P, -4, 3)\n");
	printf("\n Q(x) =");  printPoly(Q);   // 다항식 Q 출력
	printf("\n");
	
	Q = addTerm(P, 9, 2);
    
    printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
    printf("\n Q = addTerm(P, 9, 2)\n");
	printf("\n Q(x) =");  printPoly(Q);   // 다항식 Q 출력
	printf("\n");
	
	Q = addTerm(P, 8, 7);
    
    printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
    printf("\n Q = addTerm(P, 8, 7)\n");
	printf("\n Q(x) =");  printPoly(Q);   // 다항식 Q 출력
	printf("\n");
	
	
	printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
  	delTerm(&P, 2);
  	printf("\n delTerm(&P, 2)\n");
	printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
	printf("\n");
	
	P = X;
	printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
  	delTerm(&P, 5);
  	printf("\n delTerm(&P, 5)\n");
	printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
	printf("\n");
	
	P = X;	
	Q = multTerm(P, 2, 4);
	printf("\n P(x) =");  printPoly(P);   // 다항식 P 출력
	printf("\n multTerm(P, 2, 4)\n");
	printf("\n Q(x) =");  printPoly(Q);   // 다항식 Q 출력
	printf("\n\n");
	
	C = addPoly(A, B);   // 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출 
	printf(" C = A + B \n");
	printf("\n A(x) =");  printPoly(A);   // 다항식 A 출력
	printf("\n B(x) =");  printPoly(B);   // 다항식 B 출력
	printf("\n C(x) =");  printPoly(C);   // 다항식 C 출력
	printf("\n\n");
	
	printf("\n C(x) =");  printPoly(C);   // 다항식 C 출력
	eval = evaluation(C, 2.0);
	printf("\n C(2.0) = %f", eval);
	
	getchar();
}

polynomial addTerm(polynomial P , float coef, int exp){
	 int index, degree;
	 polynomial Q;
	 int i;
	 
	 degree = P.degree;
	 index = P.degree - exp;   // 지수 exp가 위한 인덱스  
	 if(exp<=degree)          // 추가할 지수가 최고차 보다 작거나 같은 경우 
	   if(P.coef[index]!=0) return P;  // 0이 아닌 값이 있는 경우 
	   else {
	         P.coef[index] = coef;    // 0인 경우 
	        return P;
	    }
	 if(exp>degree) {        // 지수 exp가 최고차 보다 큰 경우 
	 	index = exp-degree;   
	 	Q.degree = exp;       // Q의 최고차를 exp로 계수를 coef로 설정 
	 	Q.coef[0]=coef;
		for(i=1; i<index;i++) Q.coef[i] = 0;   // coef의 1번부터 (exp - P의 최고차수)-1 까지 모두 0으로  
		for(i=0; i<=degree;i++) Q.coef[index++]= P.coef[i];  // P의 계수들을 Q로 이동시킴.  Q를 return 
		return Q;
	}
}

void delTerm(polynomial *P, int exp){
	int i, count, degree, index;
	
	degree = P->degree;
	index = P->degree -exp;
		
	if(exp<degree) P->coef[index] = 0;  // exp가 P의 최고차수 보다 작을 때는 해당 계수를 0으로 함.  
	if(exp==degree) {                   // 최고차를 삭제하는 경우 
	      P->coef[0] = 0;               // 최고차의 계수를 0으로 함. 
	      count=0; 
		  for(i=0; P->coef[i]==0; i++)  // 최고차부터 몇개가 연속해서 0인가를 조사함. 그 개수가 count에 저장 
		     count++;
		  if(count>degree) {            // 모두  0인 경우 처리를 위해 
		  	   P->degree = 0; P->coef[0] = 0;
		  	   return;
		  }  
		  for(i=0; i<degree-count+1; i++)  // 앞에 0인 부분을 없애기 위해 뒷부분을 앞으로 이동  
		     P->coef[i] = P->coef[i+count];
		  P->degree=degree-count;          // P의 최고차를 수정함. 
	}
}
		     
polynomial multTerm(polynomial P, float coef, int exp){

	int i, degree, q_degree;
	polynomial Q;
	
	degree = P.degree;
	q_degree = degree + exp;   
	Q.degree = q_degree;     // Q의 최고차를 저장 
	
	for(i=0; i<=degree; i++)   // Q의 계수들을 P의 계수 * coef로 저장. 
		Q.coef[i] = P.coef[i]*coef;
	for(i=degree+1; i<=q_degree; i++)   // Q의 뒤부분을 0으로 채움. 
		Q.coef[i]=0;
		
	return Q;
}
	
	
	
	
polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;   // 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언
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
	
	degree = C.degree;     // 최고차의 계수가 0인 경우를 해결하기 위해 delTerm( )에서 한 방식과 같이 처리함. 
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
		
	return C;    // 다항식 덧셈의 결과 다항식 C를 반환
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
	  
void printPoly(polynomial P) {   // 계수가 0인 경우 출력을 하지 않기 위해 수정한 함수. 
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


