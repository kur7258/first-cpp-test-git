#include <stdio.h>
#define MAX 100

int stack[MAX];
int top;  //스택 top

void init_stack(void) {
    top = -1;
}

int push(int t) {

    stack[++top] = t;
    return t;
}

int pop(void) {
    return stack[top--];
}

int is_stack_empty(void) {
    return (top < 0);
}

int is_operator(int k) {  //연산자 확인
    return (k == '+' || k == '-' || k == '*' || k == '/');
}

int precedence(int op) {   //연산자 우선순위
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}

void postfix(char* dest, char* src) {   //변환
    char c;
    init_stack();
    while (*src) {
        if (*src == '(') {  //버림
            push(*src);
            src++;
        }
        else if (*src == ')') {
            while (stack[top] != '(') {
                *dest++ = pop();
                *dest++ = ' ';
            }
            pop();
            src++;
        }
        else if (is_operator(*src)) {
            while (!is_stack_empty() &&
                precedence(stack[top]) >= precedence(*src)) {
                *dest++ = pop();
                *dest++ = ' ';
            }
            push(*src);
            src++;
        }
        else if (*src >= '0' && *src <= '9') {
                do {
                    *dest++ = *src++;
                } while (*src >= '0' && *src <= '9');
                *dest++ = ' ';
        }
        else {
            src++;
        }
    }

    while (!is_stack_empty()) {
        *dest++ = pop();
        *dest++ = ' ';
    }
    dest--;
    *dest = 0;
}

int calc(char* p) {  //계산식
    int i, k;
    init_stack();
    while (*p) {
        if (*p >= '0' && *p <= '9') {
            i = 0;
            k = 0;
            do {
                i = i * 10 + *p - '0';
                p++;
                k++;
            } while (*p >= '0' && *p <= '9' && k < 3);
            push(i);
        }
        else if (*p == '+') {
            push(pop() + pop());
            p++;
        }
        else if (*p == '*') {
            push(pop() * pop());
            p++;
        }
        else if (*p == '-') {
            i = pop();
            push(pop() - i);
            p++;
        }
        else if (*p == '/') {
            i = pop();
            push(pop() / i);
            p++;
        }
        else {
            p++;
        }
    }
    return pop();
}

int main() {

    int r;
    char exp[256] = "1-2*3+4/5";
    char pf[256];

    printf("%s   ==>   ",exp);
    postfix(pf, exp);
    printf("%s", pf);

    r = calc(pf);
    printf("\n==>   %d", r);

    return 0;
}