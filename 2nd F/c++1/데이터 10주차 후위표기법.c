#include <stdio.h>

struct Stack {
    char data[100];
    int top;
}Stack;

void Init() {
    Stack.top = -1;
}

void Push(char data) {
    Stack.data[++Stack.top] = data;
}

char Pop() {
    return Stack.data[Stack.top--];
}

int main(void)
{
    Init();
    char input[50];
    scanf_s("%s", &input,50);
    int i = 0;
    int top = -1;
    char temp;
        while (input[i] != '\0')
        {

                if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                    switch (input[i])
                    {
                    case '+': case '-':
                    {
                        if (top == -1) {
                            Push(input[i]);
                            top++;
                            break;
                        }
                        while (top != -1) {
                            int temp = Pop();
                            top--;
                            printf("%c", temp);
                        }
                        Push(input[i]);
                        top++;
                        break;
                    }
                    case '*': case '/':
                    {
                        if (top == -1) {
                            Push(input[i]);
                            top++;
                            break;
                        }
                        int temp = Pop();
                        top--;
                        if (temp == '*' || temp == '/')
                            printf("%c", temp);
                        else {
                            Push(temp);
                            top++;
                        }
                        Push(input[i]);
                        top++;
                        break;
                    }
                    }
                }
                else
                    printf("%c", input[i]);
            i++;
        }
    for (int i = 0; i <= top; i++) {
        printf("%c", Pop());
    }
}