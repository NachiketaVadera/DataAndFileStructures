#include<stdio.h>
#include <ctype.h>

void push(char);
char pop();
int priority(char);

char stack[20];
int top = -1;

int main() {
        char expression[20];
        char *e, x;
        printf("Enter the expression: \n");
        scanf("%s",expression);
        e = expression;
        while(*e != '\0') {
                if(isalnum(*e))
                        printf("%c",*e);
                else if(*e == '(')
                        push(*e);
                else if(*e == ')') {
                        while((x = pop()) != '(')
                                printf("%c", x);
                }
                else {
                        while(priority(stack[top]) >= priority(*e))
                                printf("%c",pop());
                        push(*e);
                }
                e++;
        }
        while(top != -1)
                printf("%c",pop());
        printf("\n");
        return 0;
}

void push(char data) {
        stack[++top] = data;
}

char pop() {
        if(top == -1)
                return -1;
        else
                return stack[top--];
}

int priority(char op) {
        if(op == '(')
                return 0;
        if(op == '+' || op == '-')
                return 1;
        if(op == '*' || op == '/')
                return 2;
}
