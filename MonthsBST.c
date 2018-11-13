#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void populateInput();
void insert(char *); 
void postOrder();
void inOrder();
void preOrder();

char * months[] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};

struct node {
	char * data;
	struct node * leftChild;
	struct node * rightChild;
} *root;

int main() {
	root = NULL;
	for(int i = 0;i < 12;i++) {
		insert(months[i]);
	}
	printf("Post-order Traversal : \n");
	postOrder(root);
	printf("\nPre-order Traversal : \n");
	preOrder(root);
	printf("\nIn-order Traversal : \n");
	inOrder(root);
	return 0;
}

void insert(char * data) {
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	struct node * current;
	struct node * parent;
	
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	
	if(root == NULL) {
		root = temp;
	}
	else {
		current = root;
		parent = NULL;
		
		while(1) {
			parent = current;
			
			if(strcmp(data, parent->data) < 0) {
				current = current->leftChild;
				if(current == NULL) {
					parent->leftChild = temp;
					return;
				}
			}
			else {
				current = current->rightChild;
				if(current == NULL) {
					parent->rightChild = temp;
					return;
				}
			}
		}
	}		
}

void postOrder(struct node * node) { 
	if (node == NULL) 
		return; 
		
	// left
	postOrder(node->leftChild); 

	// right 
	postOrder(node->rightChild); 

	// node 
	printf("%s ", node->data); 
}

void preOrder(struct node * node) {
	if (node == NULL) 
		return; 
		
	// node 
	printf("%s ", node->data); 	
	
	// left
	postOrder(node->leftChild);

	// right
	postOrder(node->rightChild); 
}

void inOrder(struct node * node) {
	if (node == NULL) 
		return; 
		
	// left
	postOrder(node->leftChild); 

	// node 
	printf("%s ", node->data); 

	// right 
	postOrder(node->rightChild); 
} 


