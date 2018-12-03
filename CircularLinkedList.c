#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
        int value;
        struct node * ptr;
};

struct node * insertOrder(struct node * head, int val) {
        struct node * newNode, * temp;
        temp = head;
        newNode = (struct node*)malloc(sizeof(struct node));

        newNode->value = val;

        if(head == NULL){
                newNode->ptr = newNode;
                head = newNode;
        }
        else if(val <= head->value) {
                newNode->ptr = head;

                while(temp->ptr != head)
                        temp = temp->ptr;

                head = newNode;
                temp->ptr = head;
        }
        else {
                while(temp->ptr != head && val > temp->ptr->value)
                        temp = temp->ptr;

                newNode->ptr = temp->ptr;
                temp->ptr = newNode;
        }
        return head;
}


struct node * deleteVal(struct node * head, int val) {
        struct node * temp, * nodeDeleted;
        temp = head;
        if(head == NULL)
                printf("List is empty\n");
        else if(head->value == val) {
                while(temp->ptr != head)
                        temp = temp->ptr;

                temp->ptr = head->ptr;
                free(head);
                head = temp->ptr;
        }
        else {
                temp = head;
                while (temp->ptr != head && val != temp->ptr->value)
                        temp = temp->ptr;

                if(temp->ptr == head)
                        printf("Given value is not Found\n");
                else {
                        nodeDeleted = temp->ptr;
                        temp->ptr = temp->ptr->ptr;
                        free(nodeDeleted);
                }
        }
        return head;
}

void display(struct node * head) {
        struct node * temp = head;
        if(head == NULL)
                printf("The list is Empty\n");

        else {
                do {
                        printf("%d ",temp->value);
                        temp = temp->ptr;
                } while(temp != head);
                printf("\n");
        }
}

int main() {
        struct node * head;
        head = NULL;
        int n, val;
        while(true) {
                printf("1: Insert\n");
                printf("2: Delete\n");
                printf("3: Display\n");
                printf("4: Exit\n");
                printf("Enter your choice: \n");
                scanf("%d", &n);
                switch(n) {
                        case 1:
                                printf("\n");
                                printf("Enter the value to insert: \n");
                                scanf("%d", &val);
                                head = insertOrder(head, val);
                                printf("\n");
                                break;
                        case 2:
                                printf("\n");
                                printf("Enter the value to delete: \n");
                                scanf("%d", &val);
                                head = deleteVal(head, val);
                                printf("\n");
                                break;
                        case 3:
                                printf("\n");
                                display(head);
                                printf("\n");
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("\n");
                                printf("Invalid choice!\n");
                }
        }
        return 0;
}
