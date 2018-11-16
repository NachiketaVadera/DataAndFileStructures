#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int top = -1,stack[MAX];
void push();
void pop();
void display();

int main() {
        int choice;
        while(true) {
                printf("1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
                printf("Enter your choice(1-4):\n");
                scanf("%d",&choice);

                switch(choice) {
                case 1:
                        push();
                        break;
                case 2:
                        pop();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        exit(0);
                default:
                        printf("\nKindly enter valid a choice.");
                }
        }
        return 0;
}

void push() {
        int data;
        if(top==MAX-1) {
                printf("Stack Overflow\n");
        }
        else {
                printf("Enter element to push:\n");
                scanf("%d",&data);
                top = top + 1;
                stack[top] = data;
        }
}

void pop() {
        if(top == -1) {
                printf("Stack Underflow\n");
        }
        else {
                printf("\nDeleted element is %d\n",stack[top]);
                top = top - 1;
        }
}

void display() {
        if(top == -1) {
                printf("Stack Underflow\n");
        }
        else {
                for(int i=top;i>=0;--i)
                printf("%d\n",stack[i]);
        }
}
