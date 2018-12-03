#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
        int value;
        struct TreeNode * left;
        struct TreeNode * right;
};

struct TreeNode * insert(struct TreeNode * r, int val) {
        struct TreeNode * newnode, * temp;
        newnode = (struct TreeNode * ) malloc(sizeof(struct TreeNode));
        if (newnode == NULL) {
                printf("Malloc failed!");
                return r;
        }
        newnode -> value = val;
        newnode -> left = NULL;
        newnode -> right = NULL;
        if (r == NULL) {
                r = newnode;
                return r;
        }
        temp = r;
        while (1) {
                if (val < (temp -> value)) {
                        if (temp -> left == NULL) {
                                temp -> left = newnode;
                                break;
                        }
                        temp = temp -> left;
                } else {
                        if (temp -> right == NULL) {
                                temp -> right = newnode;
                                break;
                        }
                        temp = temp -> right;
                }
        }
        return r;
}

void preorder(struct TreeNode * t) {
        if (t != NULL) {
                printf("%d | ", t -> value);
                preorder(t -> left);
                preorder(t -> right);
        }
}
void inorder(struct TreeNode * t) {
        if (t != NULL) {

                preorder(t -> left);
                printf("%d | ", t -> value);
                preorder(t -> right);
        }
}
void postorder(struct TreeNode * t) {
        if (t != NULL) {

                preorder(t -> left);
                preorder(t -> right);
                printf("%d | ", t -> value);
        }
}

void main() {
        struct TreeNode * root;
        int x, i = 0;
        int BT[50];
        root = NULL;
        printf("Enter the values to be inserted in binary tree [-1 to stop]:\n");
        while (x != -1) {
                scanf("%d", & BT[i]);
                x = BT[i];
                i++;
        }
        i = 0;
        while (BT[i] != -1) {
                root = insert(root, BT[i]);
                i++;
        }

        printf("1: Preorder\n2: Inorder\n3: Postorder\n");
        printf("Enter your choice: \n");
        scanf("%d", &x);
        switch (x) {
        case 1:
                preorder(root);
                break;
        case 2:
                inorder(root);
                break;
        case 3:
                postorder(root);
                break;

        }

}
