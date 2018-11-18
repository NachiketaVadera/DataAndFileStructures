#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert(int value);
void display();
void delete();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main() {
	int choice;
	int value;

	while(1) {
		printf("1.Insert element to queue \n");
		printf("2.Delete element from queue \n");
		printf("3.Display all elements of queue \n");
		printf("4.Quit \n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter value to insert:\n");
				scanf("%d",&value);
				insert(value);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
		}
	}	
	return 0;
}

void insert(int value) {
	if((rear+1)%MAX == front) {
		printf("Queue is full\n");
	}
	else {
		rear = (rear+1)%MAX;
		queue_array[rear] = value;
	}
}

void delete() {
	if(front == rear) {
		front = -1;
		rear = -1;
		printf("Queue is empty\n");	
	}
	else {
		front = (front+1)%MAX;
		queue_array[front] = NULL;
		
	}
}

void display() {
	int i;
	for(i = 0;i < MAX;i++) {
		printf("%d\n",queue_array[i]);
	}
}

