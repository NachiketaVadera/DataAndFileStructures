#include <stdio.h>
#include <ctype.h>

void push(int);
int pop();

int stack[10];
int top = -1;

int main() {
        char expression[10];
        char *e;
        int a, b, c, number;
        printf("Enter the expression: \n");
        scanf("%s", expression);
        e = expression;
        while(*e != '\0') {
                if(isdigit(*e)) {
                        number = *e - 48;
                        push(number);
                }
                else {
                        a = pop();
                        b = pop();
                        switch(*e) {
                                case '+':
                                        c = a + b;
                                        break;
                                case '-':
                                        c = b - a;
                                        break;
                                case '*':
                                        c = a * b;
                                        break;
                                case '/':
                                        c = b / a;
                                        break;
                        }
                        push(c);
                }
                e++;
        }
        printf("%s = %d\n",expression,pop());
        return 0;

}

void push(int data) {
        stack[++top] = data;
}

int pop() {
        return stack[top--];
}
