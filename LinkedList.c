#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

struct node *start;
int count = 0;

void insertAtFront(int);
void insertAtEnd(int);
void traverse();
void deleteFromFront();
void deleteFromEnd();
struct node *reverse();

int main() {
	start = NULL;
	int input, data;
	while(true) {
		printf("1. Insert an element at beginning of linked list.\n");
		printf("2. Insert an element at end of linked list.\n");
		printf("3. Traverse linked list.\n");
		printf("4. Delete element from beginning.\n");
		printf("5. Delete element from end.\n");
		printf("6. Reverse the linked list.\n");
		printf("7. Exit\n");

		scanf("%d", &input);

		switch(input) {
			case 1:
				printf("Enter value to insert : \n");
				scanf("%d", &data);
				insertAtFront(data);
				break;
			case 2:
				printf("Enter value to insert : \n");
				scanf("%d", &data);
				insertAtEnd(data);
				break;
			case 3:
				traverse();
				break;
			case 4:
				deleteFromFront();
				break;
			case 5:
				deleteFromEnd();
				break;
			case 6:
				start = reverse();
				traverse();
			case 7:
				exit(0);
		}
	}
	return 0;
}

void insertAtFront(int value) {
	struct node *t, *temp;
	t = (struct node*)malloc(sizeof(struct node));
        count++;
	if (start == NULL) {
		start = t;
		start->data = value;
		start->next = NULL;
		return;
	}

	t->data = value;
	t->next = start;
	start = t;
}

void insertAtEnd(int value) {
	struct node *t, *temp;
	t = (struct node*)malloc(sizeof(struct node));
	count++;

	if (start == NULL) {
		start = t;
		start->data = value;
		start->next = NULL;
		return;
	}

	temp = start;

	while (temp->next != NULL)
		temp = temp->next;  

	temp->next = t;
	t->data = value;
	t->next = NULL;
}

void traverse() {
	struct node *t;
	t = start;

	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}

	printf("There are %d elements in linked list.\n", count);

	while (t->next != NULL) {
		printf("%d -> ", t->data);
		t = t->next;
	}
	printf("%d -> NULL \n", t->data);
}

void deleteFromFront() {
	struct node *t;
	int n;

	if (start == NULL) {
		printf("Linked list is already empty.\n");
		return;
	}

	n = start->data;
	t = start->next;
	free(start);
	start = t;
	count--;

	printf("%d deleted from beginning successfully.\n", n);
}

void deleteFromEnd() {
	struct node *u, *temp;
	int n;

	if (start == NULL) {
		printf("Linked list is already empty.\n");
		return;
	}

	count--;
	temp = start;

	while (temp->next != NULL) {
		u = temp;
		temp = temp->next;
	}

	n = temp->data;
	u->next = NULL;
	free(temp);

	printf("%d deleted from end successfully.\n", n);
}

struct node *reverse() {
	struct node *current = start;
	struct node *prev = NULL, *next = NULL;
	
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
