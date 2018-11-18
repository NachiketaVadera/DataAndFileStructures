#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

bool isEmpty();
bool isFull();
void insert(int);
int delete();
void display();

int queue[SIZE];
int front = 0;
int rear = -1;
int count = 0;

int main() {
        int choice, value;
        while (true) {
                printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
                printf("\nEnter your choice:\n");
                scanf("%d", &choice);
                switch (choice) {
                        case 1:
                                printf("Enter data to insert: \n");
                                scanf("%d", &value);
                                insert(value);
                                break;
                        case 2:
                                printf("%d removed from the queue.\n", delete());
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("Kindly enter a valid choice.\n");
                }
        }
        return 0;
}

bool isEmpty() {
        return count == 0;
}

bool isFull() {
        return count == SIZE;
}

void insert(int data) {
        if(!isFull()) {
                if(rear == SIZE-1) {
                        rear = -1;
                }
                queue[++rear] = data;
                count++;
        }
        else {
                printf("Queue overflow!\n");
        }
}

int delete() {
        if (!isFull()) {
                int data = queue[front++];
                count--;
                return data;
        }
        else {
                printf("Queue underflow!\n");
                return 0;
        }
}

void display() {
        if (isEmpty()) {
                printf("Queue underflow!\n");
        }
        else {
                printf("=====================================\n");
                for (int i = front;i <= rear;i++) {
                        printf("%d ", queue[i]);
                }
                printf("\n");
                printf("=====================================\n");
        }
}
