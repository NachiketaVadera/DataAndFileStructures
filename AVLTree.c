#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	int height;
	struct node * leftChild;
	struct node * rightChild;
} *root;

int height(struct node *);
int getBalance(struct node *);
int getMaximum(int, int);
struct node * insert(struct node *, int);
struct node * newNode(int);
struct node * leftRotate(struct node *);
struct node * rightRotate(struct node *);
void postOrder(struct node *);
void inOrder(struct node *);
void preOrder(struct node *);
void printHeight(struct node *);
void printElementsOnLevel(struct node *, int);

int main() {
	int size;
	root = NULL;
	printf("Enter the number of inputs: \n");
	scanf("%d", &size);
	for (int i = 0;i < size;i++) {
		int val;
		printf("Enter value %d:\n", i);
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("========== PRE-ORDER ==========\n");
	preOrder(root);
	printf("\n");
	printf("========== POST-ORDER ==========\n");
	postOrder(root);
	printf("\n");
	printf("========== IN-ORDER ==========\n");
	inOrder(root);
	printf("\n");
	printf("========== LEVEL ==========\n");
	printHeight(root);
	return 0;
}

int getMaximum(int a, int b) {
	return (a > b)? a : b;
}

int height(struct node * n) {
	if (n == NULL) 
		return 0;
	return n->height;	
}

int getBalance(struct node * n) {
	if (n == NULL) 
		return 0; 
	return height(n->leftChild) - height(n->rightChild);
}

struct node * newNode(int value) { 
    struct node * node = (struct node *)malloc(sizeof(struct node)); 
    node->data = value; 
    node->leftChild = NULL; 
    node->rightChild = NULL; 
    node->height = 1;
    return(node); 
} 

struct node * insert(struct node * node, int value) { 

	if (node == NULL) 
		return(newNode(value)); 

	if (value < node->data) 
		node->leftChild  = insert(node->leftChild, value); 
	else if (value > node->data) 
		node->rightChild = insert(node->rightChild, value); 
	else
		return node; 

	node->height = 1 + getMaximum(height(node->leftChild), height(node->rightChild)); 

	int balance = getBalance(node); 

	if (balance > 1 && value < node->leftChild->data) 
		return rightRotate(node); 

	if (balance < -1 && value > node->rightChild->data) 
		return leftRotate(node); 

	if (balance > 1 && value > node->leftChild->data) { 
		node->leftChild =  leftRotate(node->leftChild); 
		return rightRotate(node); 
	} 

	if (balance < -1 && value < node->rightChild->data) { 
		node->rightChild = rightRotate(node->rightChild); 
		return leftRotate(node); 
	} 
	
	return node; 
}

struct node * leftRotate(struct node * node) {
	struct node * newRoot = node->rightChild;
	struct node * left = newRoot->leftChild;

	newRoot->leftChild = node;
	node->rightChild = left;

	node->height = getMaximum(height(node->leftChild), height(node->rightChild))+1; 
	newRoot->height = getMaximum(height(newRoot->leftChild), height(newRoot->rightChild))+1; 

	return newRoot; 
} 

struct node * rightRotate(struct node * node) {
	struct node * newRoot = node->leftChild; 
	struct node * right = newRoot->rightChild; 

	newRoot->rightChild = node;
	node->leftChild = right;
	
	node->height = getMaximum(height(node->leftChild), height(node->rightChild))+1; 
	newRoot->height = getMaximum(height(newRoot->leftChild), height(newRoot->rightChild))+1;

	return newRoot; 
}

void postOrder(struct node * node) { 
	if (node == NULL) 
		return; 
		
	postOrder(node->leftChild);  
	postOrder(node->rightChild); 
	printf("%d ", node->data); 
}

void preOrder(struct node * node) {
	if (node == NULL) 
		return; 
	
	printf("%d ", node->data); 	
	postOrder(node->leftChild);
	postOrder(node->rightChild); 
}

void inOrder(struct node * node) {
	if (node == NULL) 
		return; 
		
	postOrder(node->leftChild); 
	printf("%d ", node->data); 
	postOrder(node->rightChild); 
}

void printHeight(struct node * root) {
	int h = height(root);
	for (int i = 1;i <= h;i++) {
		printElementsOnLevel(root, i);
		printf("\n"); 
	}
}

void printElementsOnLevel(struct node * root, int level) {
	if (root == NULL)
		return;
	if (level == 1) 
		printf("%d ", root->data);
	else if (level > 1) {
		printElementsOnLevel(root->leftChild, level-1); 
	        printElementsOnLevel(root->rightChild, level-1); 
	}
}









