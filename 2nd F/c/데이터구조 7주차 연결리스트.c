#include <stdio.h>
#include <stdlib.h>

float coef;
typedef struct ListNode {
    float coef;  //���
    int expo; //����
    struct ListNode* link;
}ListNode;

typedef struct ListHead {
    ListNode* head;
}ListHead;

ListHead* createLinkedList(void) {  //���
    ListHead* L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}

void appendTerm(ListHead* L, float coef, int exp) {  //���׽�
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

void addPoly(ListHead* A, ListHead* B, ListHead* C) {  //�� ����
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

void addTerm(ListHead* L, float coef, int expo) {  //�� �߰�
    ListNode* pA = L->head;
    ListNode* newNode;
    ListNode* p;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expo = expo;

    for (; pA; pA = pA->link) {
        if (pA->expo == expo) {
            printf("\n\n �̹� �����ϴ� ���Դϴ�. / ���� �� ���");
            break;
        }
        if (pA->link == NULL) {
            appendTerm(L, coef, expo);
            break;
        }
    }
}

void delTerm(ListHead* L, int expo) {  //�� ����
    ListNode* pA = L->head;

    for (; pA; pA = pA->link) {
        if (pA->expo == expo) {
            pA->expo = NULL;
            pA->coef = 0;
            break;
        }
        if (pA->link == NULL) {
            printf("\n\n ���� ���Դϴ�. / ���� �� ���");
        }
    }
}

void printPoly(ListHead* L) {  //���
    ListNode* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL)printf("+");
    }
}

void mulTerm(ListHead* P, float coef, int expo) {  //��
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
    printf("\n\n P�� Q�� ���� �� Q(x) =");
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

    addPoly(A, B, C); //����
    printf("\n\n A + B�� C(x) =");
    printPoly(C);

    addTerm(A, 5, 4); //�߰�
    printf("\n\n A�� ���� �߰����� �� A(x) =");
    printPoly(A);

    delTerm(A, 8); //����
    printf("\n\n A���� ���� �������� �� A(x) =");
    printPoly(A);

    appendTerm(P, 3, 4); //�� ��� ��
    appendTerm(P, 2, 3);
    appendTerm(P, 1, 2);
    printf("\n\n ���ϱ� �ع��� P(x) =");
    printPoly(P);

    mulTerm(P, 2, 3); //��


    getchar();
}