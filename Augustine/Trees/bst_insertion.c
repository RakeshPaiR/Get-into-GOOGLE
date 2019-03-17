#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* l;
	struct node* r;
}*root = NULL, *ptr;

struct node* new_node(int data) {
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->l = NULL;
	ptr->r = NULL;
	return ptr;
}

void insert_new_node(struct node* head, struct node* ptr) {
	if(head->data > ptr->data){
		if(head->l == NULL) {
			head->l = ptr;
			return;
		}
		else
			insert_new_node(head->l, ptr);
	}
	else {
		if(head->r == NULL) {
			head->r = ptr;
			return;
		}
		else
			insert_new_node(head->r, ptr);
	}
}
void inorder_traversal(struct node *ptr){
	if(ptr == NULL)
		return;

	inorder_traversal(ptr->l);
	printf(" %d ", ptr->data);
	inorder_traversal(ptr->r);
}
int main() {
	int choice, num;
	while(1) {
		printf("\nMenu\n1.Insert\n2.Display\n3.Exit");
		scanf("%d", &choice);
		if(choice == 3)
			break;
		else if(choice == 1){
			printf("Enter the number to be inserted");
			scanf("%d", &num);
			ptr = new_node(num);
			if(root != NULL)
				insert_new_node(root, ptr);
			else
				root = ptr;
		}
		else if(choice == 2)
			inorder_traversal(root);
	}
}


