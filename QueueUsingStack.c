#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void pushStack_1(int);
void pushStack_2(int);
int popStack_1();
int popStack_2();
void enqueue();
void dequeue();
void display();
void init();

int stack_1[10], stack_2[10];
int top1 = -1, top2 = -1;
int count = 0;

int main() {
	int choice;
	printf("\n1 - Enqueue element into queue");
	printf("\n2 - Dequeu element from queue");
	printf("\n3 - Display from queue");
	printf("\n4 - Exit");
	init();
	while (true) {
		printf("\nEnter choice: \n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Kindly enter a valid choice.");
		}
	}
        return 0;
}

void init() {
	top1 = top2 = -1;
}

void pushStack_1(int data) {
	stack_1[++top1] = data;
}

int popStack_1() {
	return(stack_1[top1--]);
}

void pushStack_2(int data) {
	stack_2[++top2] = data;
}

int popStack_2() {
	return(stack_2[top2--]);
}

void enqueue() {
	int data, i;
	printf("Enter data into queue : \n");
	scanf("%d", &data);
	pushStack_1(data);
	count++;
}

void dequeue() {
	if (top1 == -1 && top2 == -1) {
		printf("Queue is Empty");
	}
	else {
		int i;
		for (i = 0;i <= count;i++) {
			pushStack_2(popStack_1());
		}
		popStack_2();
		count--;
		for (i = 0;i <= count;i++) {
			pushStack_1(popStack_2());
		}
	}
}

void display() {
	int i;
	for (i = 0;i <= top1;i++) {
		printf(" %d ", stack_1[i]);
	}

}
