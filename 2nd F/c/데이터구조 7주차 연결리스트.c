#include <stdio.h>
#include <stdlib.h>

float coef;
typedef struct ListNode {
    float coef;  //계수
    int expo; //지수
    struct ListNode* link;
}ListNode;

typedef struct ListHead {
    ListNode* head;
}ListHead;

ListHead* createLinkedList(void) {  //노드
    ListHead* L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}

void appendTerm(ListHead* L, float coef, int exp) {  //다항식
    ListNode* newNode;
    ListNode* p;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expo = exp;
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }
    else {
        p = L->head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = newNode;
    }
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {  //항 덧셈
    ListNode* pA = A->head;
    ListNode* pB = B->head;
    float sum;

    while (pA && pB) {
        if (pA->expo == pB->expo) {
            sum = pA->coef + pB->coef;
            appendTerm(C, sum, pA->expo);
            pA = pA->link;
            pB = pB->link;
        }
        else if (pA->expo > pB->expo) {
            appendTerm(C, pA->coef, pA->expo);
            pA = pA->link;
        }
        else {
            appendTerm(C, pB->coef, pB->expo);
            pB = pB->link;
        }
    }
    for (; pA != NULL; pA = pA->link)
        appendTerm(C, pA->coef, pA->expo);

    for (; pB != NULL; pB = pB->link)
        appendTerm(C, pB->coef, pB->expo);
}

void addTerm(ListHead* L, float coef, int expo) {  //항 추가
    ListNode* pA = L->head;
    ListNode* newNode;
    ListNode* p;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expo = expo;

    for (; pA; pA = pA->link) {
        if (pA->expo == expo) {
            printf("\n\n 이미 존재하는 항입니다. / 기존 항 출력");
            break;
        }
        if (pA->link == NULL) {
            appendTerm(L, coef, expo);
            break;
        }
    }
}

void delTerm(ListHead* L, int expo) {  //항 삭제
    ListNode* pA = L->head;

    for (; pA; pA = pA->link) {
        if (pA->expo == expo) {
            pA->expo = NULL;
            pA->coef = 0;
            break;
        }
        if (pA->link == NULL) {
            printf("\n\n 없는 항입니다. / 기존 항 출력");
        }
    }
}

void printPoly(ListHead* L) {  //출력
    ListNode* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL)printf("+");
    }
}

void mulTerm(ListHead* P, float coef, int expo) {  //곱
    ListHead* Q;
    Q = createLinkedList();
    ListNode* pP = P->head;
    float coefMult;
    int expMult;

    for (; pP; pP = pP->link) {
        coefMult = pP->coef * coef;
        expMult = pP->expo * expo;
        appendTerm(Q, coefMult, expMult);
    }
    printf("\n\n P에 Q를 곱한 식 Q(x) =");
    printPoly(Q);
}


void main(void) {
    ListHead* A, * B, * C, * P, * Z;

    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();
    P = createLinkedList();
    Z = createLinkedList();

    appendTerm(A, 5, 3);
    appendTerm(A, 3, 2);
    appendTerm(A, 7, 1);
    printf("\n A(x) =");
    printPoly(A);

    appendTerm(B, 2, 4);
    appendTerm(B, 2, 3);
    appendTerm(B, 3, 1);
    appendTerm(B, 1, 0);
    printf("\n\n B(x) =");
    printPoly(B);

    addPoly(A, B, C); //덧셈
    printf("\n\n A + B식 C(x) =");
    printPoly(C);

    addTerm(A, 5, 4); //추가
    printf("\n\n A에 항을 추가했을 때 A(x) =");
    printPoly(A);

    delTerm(A, 8); //삭제
    printf("\n\n A에서 항을 삭제했을 때 A(x) =");
    printPoly(A);

    appendTerm(P, 3, 4); //곱 대기 식
    appendTerm(P, 2, 3);
    appendTerm(P, 1, 2);
    printf("\n\n 곱하기 해버릴 P(x) =");
    printPoly(P);

    mulTerm(P, 2, 3); //곱


    getchar();
}