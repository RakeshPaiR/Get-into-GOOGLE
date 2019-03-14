#include<iostream>
using namespace std;
#define COUNT 5

struct Node {
	Node *left;
	int data;
	Node *right;
};

struct Queue {
	Node *addr;
	Queue *link;
};

struct Result {
	Node *Res;
	Node *Parent;
};

Queue *front =NULL;
Queue *rear = NULL;

void enQ(Node *address) {
	Queue *newNode = new Queue;
	newNode -> addr = address;
	newNode -> link = NULL;
	if (front == NULL) {
		front = rear = newNode;
	}
	else {
		rear -> link = newNode;
		rear = newNode;
	}
}

void deQ() {
	if (front != NULL) {
		front = front -> link;
		if (front == NULL) {
			rear = NULL;
		}
	}
}

Node *createNode(int val) {
	Node *newNode = new Node;
	newNode -> data = val;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}
Node *insertNode(Node *root,int val) {
	Node *temp = createNode(val);
	if (root == NULL) {
		root = temp;
	}
	else {
		if (front -> addr -> left == NULL) {
			front -> addr -> left = temp;
		}
		else {
			front -> addr -> right = temp;
			deQ();
		}
	}
	enQ(temp);
	return root;
}

void findDeepNode(Node *root,int lvl, int maxLvl,Node *res,Node *parent) {
	if (root != NULL) {
		Node *temp = root;
		findDeepNode(root -> left, ++lvl,maxLvl,res,parent);
		if (lvl >= maxLvl) {
			res = root;
			maxLvl = lvl;
			parent = temp;
		}
		findDeepNode(root->right,lvl,maxLvl,res,parent);
	}
}

Result *deepestNode(Node *root) {
	Node *res = NULL;
	int maxLvl = -1;
	Node *parent = NULL;
	findDeepNode(root,0,maxLvl,res,parent);
	Result *solution = new Result;
	solution -> Res = res;
	solution -> Parent = parent;
}
Result *findNode(Node *root,int val,Node *temp){
	Result *solution = new Result;
	if (root -> data == val) {
		solution -> Res = root;
		solution -> Parent = temp;
		return solution;
	}
	else {
		temp = root;
		findNode(root->left,val,temp);
		findNode(root->right,val,temp);
	}
}

Node *deleteNode(Node *root, int val) {
	Result *resNode = deepestNode(root);
	Node *repNode = resNode -> Res;
	Node *parentNode = resNode -> Parent;
	Result *tempNode = findNode(root,val,NULL);
	Node *delNode = tempNode -> Res;
	Node *parentDelNode = tempNode -> Parent;
	/*if (delNode != repNode){
		if (parentNode -> left == repNode)	parentNode -> left = NULL;
		else parentNode -> right = NULL;
		if (parentDelNode -> left == delNode)	parentDelNode -> left = repNode;
		else parentDelNode -> right = repNode;
		repNode -> left = delNode -> left;
		repNode -> right = repNode -> right;
	}
	//free(delNode);
	*/
	return root;
}

void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  

int main() {
	int val;
	Node *root = NULL;
	cout<<"Enter data: ",cin>>val;
	do {	
		root = insertNode(root,val);
		cout<<"Enter data: ",cin>>val;
	} while(val != -1);
	print2D(root);
	cout<<"Enter Node to be deleted: ",cin>>val;
	do {
		root = deleteNode(root,val);
		cout<<"Enter Node to be deleted: ",cin>>val;
	}while(val != -1);
	print2D(root);
}
