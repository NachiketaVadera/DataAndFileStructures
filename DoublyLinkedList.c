#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
        int value;
        struct Node * lptr;
        struct Node * rptr;
};

void insert_front(struct Node ** L, struct Node ** R, int val) {
        struct Node * newNode;
        newNode = (struct Node * ) malloc(sizeof(struct Node));

        newNode -> value = val;

        if ( * L == NULL) {
                * L = * R = newNode;
                ( * L) -> lptr = NULL;
                ( * L) -> rptr = NULL;
                return;
        }
        newNode -> rptr = * L;
        newNode -> lptr = NULL;
        ( * L) -> lptr = newNode;
        * L = newNode;
}

void insert_rear(struct Node ** L, struct Node ** R, int val) {
        struct Node * newNode;
        newNode = (struct Node * ) malloc(sizeof(struct Node));

        newNode -> value = val;

        if ( * L == NULL) {
                * L = * R = newNode;
                ( * L) -> lptr = NULL;
                ( * L) -> rptr = NULL;
                return;
        }
        newNode -> lptr = * R;
        newNode -> rptr = NULL;
        ( * R) -> rptr = newNode;
        * R = newNode;
}

void insert_order(struct Node ** L, struct Node ** R, int val) {
        struct Node * newNode;
        struct Node * temp = * L;
        newNode = (struct Node * ) malloc(sizeof(struct Node));

        newNode -> value = val;

        if ( * L == NULL) {
                * L = * R = newNode;
                ( * L) -> lptr = NULL;
                ( * L) -> rptr = NULL;
                return;
        }

        if (val <= ( * L) -> value) {
                newNode -> rptr = * L;
                newNode -> lptr = NULL;
                ( * L) -> lptr = newNode;
                * L = newNode;
        } else if (val >= ( * R) -> value) {
                newNode -> lptr = * R;
                newNode -> rptr = NULL;
                ( * R) -> rptr = newNode;
                * R = newNode;
        } else {
                while (temp -> value <= val)
                        temp = temp -> rptr;

                newNode -> lptr = temp -> lptr;
                newNode -> rptr = temp;
                temp -> lptr -> rptr = newNode;
                temp -> lptr = newNode;
        }
}

void insert_specs(struct Node ** L, struct Node ** R, int val) {
        int sval, n;
        struct Node * newNode;
        struct Node * temp = * L;
        newNode = (struct Node * ) malloc(sizeof(struct Node));

        newNode -> value = val;

        do {
                printf("Enter after which value you want to insert:\n");
                scanf("%d", & sval);
                n = 1;
                temp = * L;
                while (temp -> value != sval) {
                        temp = temp -> rptr;

                        if (temp == NULL) {
                                printf("your given value is not found\n");
                                n = 0;
                                break;
                        }
                }
        } while (n == 0);

        newNode -> lptr = temp;
        newNode -> rptr = temp -> rptr;
        if (temp != * R) temp -> rptr -> lptr = newNode;
        temp -> rptr = newNode;

        if (temp == * R)
                *
                R = newNode;
}

void del_front(struct Node ** Head, struct Node ** Rear) {
        struct Node * delete;

        if ( * Head == NULL) {
                printf("The list is Empty\n");
                return;
        }

        if (( * Head) -> rptr == NULL && ( * Head) -> lptr == NULL) {
                printf("%d is removed\n", ( * Head) -> value);
                free( * Head);
                * Head = * Rear = NULL;
                return;
        }

        delete = * Head;
        * Head = ( * Head) -> rptr;
        ( * Head) -> lptr = NULL;
        printf("%d is removed\n", delete -> value);
        free(delete);

}

void del_end(struct Node ** Head, struct Node ** Rear) {
        struct Node * delete;
        delete = * Rear;

        if ( * Head == NULL) {
                printf("The list is Empty\n");
                return;
        }
        if ( * Head == * Rear) {
                printf("%d is removed\n", ( * Head) -> value);
                free( * Head);
                * Head = * Rear = NULL;
                return;
        }

        ( * Rear) = ( * Rear) -> lptr;
        ( * Rear) -> rptr = NULL;
        printf("%d is removed\n", delete -> value);
        free(delete);
}

void del_specific(struct Node ** Head, struct Node ** Rear, int val) {
        struct Node * temp;
        temp = * Head;

        if ( * Head == NULL) {
                printf("The list is Empty\n");
                return;
        }

        if (val == ( * Head) -> value) {
                if ( * Head == * Rear) {
                        printf("%d is removed\n", ( * Head) -> value);
                        free( * Head);
                        * Head = * Rear = NULL;
                } else {
                        temp = * Head;
                        * Head = ( * Head) -> rptr;
                        ( * Head) -> lptr = NULL;
                        printf("%d is removed\n", temp -> value);
                        free(temp);
                }
        } else if (val == ( * Rear) -> value) {

                temp = * Rear;
                ( * Rear) = ( * Rear) -> lptr;
                ( * Rear) -> rptr = NULL;
                printf("%d is removed\n", temp -> value);
                free(temp);
        } else {
                while (temp != NULL && temp -> value != val)
                        temp = temp -> rptr;

                if (temp == NULL) {
                        printf("Value is not found\n");
                        return;
                }

                temp -> lptr -> rptr = temp -> rptr;
                temp -> rptr -> lptr = temp -> lptr;
                printf("%d is removed\n", temp -> value);
                free(temp);
        }
}

void display(struct Node * H) {
        struct Node * temp;
        temp = H;

        if (temp == NULL)
                printf("List is empty");

        printf("The Numbers in list is..");
        while (temp != NULL) {
                printf("%d ", temp -> value);
                temp = temp -> rptr;
        }
        printf("\n");

}

int main() {
        struct Node * Head;
        struct Node * Rear;
        Head = Rear = NULL;
        int val, n;
        while (true) {
                printf("1: Insert at fornt\n");
                printf("2: Insert at rear\n");
                printf("3: Insert in order\n");
                printf("4: Insert value after specific value\n");
                printf("5: Delete from front\n");
                printf("6: Delete from end\n");
                printf("7: Delete a specific value\n");
                printf("8: Display\n");
                printf("9: Exit\n");
                printf("Enter your choice:\n");
                scanf("%d", & n);
                switch (n) {
                case 1:
                        printf("Enter the value you want to insert:\n");
                        scanf("%d", & val);
                        insert_front( & Head, & Rear, val);
                        break;
                case 2:
                        printf("Enter the value you want to insert:\n");
                        scanf("%d", & val);
                        insert_rear( & Head, & Rear, val);
                        break;
                case 3:
                        printf("Enter the value you want to insert:\n");
                        scanf("%d", & val);
                        insert_order( & Head, & Rear, val);
                        break;
                case 4:
                        printf("Enter the value you want to insert:\n");
                        scanf("%d", & val);
                        insert_specs( & Head, & Rear, val);
                        break;
                case 5:
                        del_front( & Head, & Rear);
                        break;
                case 6:
                        del_end( & Head, & Rear);
                        break;
                case 7:
                        printf("Enter value you want to be deleted\n");
                        scanf("%d", & val);
                        del_specific( & Head, & Rear, val);
                        break;
                case 8:
                        display(Head);
                        break;
                case 9:
                        exit(0);
                default:
                        printf("Invalid choice!\n");
                }
        }
        return 0;
}
