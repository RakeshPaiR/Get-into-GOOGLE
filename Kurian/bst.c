#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* right;
	struct node* left;
}*p,*rt;

struct node* root=NULL;
int k;

void disp(struct node* temp){
	if(temp==NULL)
		return ;
	else{

		disp(temp->left);
		printf("%d ",temp->data);
		disp(temp->right);
	}
}

void insert(){
	
	p=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the data \n");
	scanf("%d%*c",&p->data);
	p->left=NULL;
	p->right=NULL;

	if(root==NULL){
		root=p;
	}
	else{
		k=0;
		rt=root;
		while(k==0){
			if(p->data>rt->data){
				if(rt->right==NULL){
					k=1;
					rt->right=p;
				}
				else
					rt=rt->right;	
			}
			else{
				if(rt->left==NULL){
					k=1;
					rt->left=p;
				}
				else
					rt=rt->left;
			}
		}

	}
	disp(root);
}


int main(){

	char ch;

	do{
		insert();
		printf("\n insert again into tree (y/n)? ");
		scanf("%c%*c",&ch);
	}while(ch=='y');



}