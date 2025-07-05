#include <stdio.h>
#include <ctype.h>

int top = -1;
char stack[100];

void push(char c) {
    if (top == 99) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[100];
    char postfix[100];
    int i = 0, j = 0;
    char c;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j] = c;
            j++;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j] = pop();
                j++;
            }
            if (top != -1 && stack[top] == '(') {
                pop(); // remove '('
            }
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j] = pop();
                j++;
            }
            push(c);
        }

        i++;
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
