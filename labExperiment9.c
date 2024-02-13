#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *Node;

void display(Node root){
	if (root!=NULL){
		display(root->left);
		printf("%d \t",root->data);
		display(root->right);
	}
}

Node createnode(Node root,int item){
	Node temp;
	temp=(Node)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
// all functions related to trees SHOULD be recursive for easier stuff 

Node insertleft(Node root,int item){
	root->left=createnode(root,item);
	return root->left;
}

Node insertright(Node root,int item){
	root->right=createnode(root,item);
	return root->right;
}

int countnode(Node root){
	if(root==NULL)
		return 0;
	else
		return countnode(root->left)+countnode(root->right)+1;
}

int height(Node root){
	if(root==NULL)
		return -1;
	else{
		int lt=height(root->left);
		int rt=height(root->right);
		if(lt>rt)
			return lt+1;
		else
			return rt+1;
	}
}

int leafnodes(Node root){
	if(root==NULL)
		return 0;
	else if(root->right==NULL&&root->left==NULL)
		return 1;
	else{
		return leafnodes(root->left)+leafnodes(root->right);
		
	}
	
}

int nonleaf(Node root){
if(root==NULL || (root->left==NULL&&root->right==NULL))
	return 0;
else{
	return nonleaf(root->left)+nonleaf(root->right)+1;
	}	
}

int main(){
	Node root=NULL;
	root=createnode(root,10);
	insertleft(root,20);
	insertright(root,30);
	insertleft(root->left,60);
	insertright(root->left,50);
	insertright(root->right,40);
	insertright(root->left->right,70);
	printf("\n The inorder traversal is: \n");
	display(root);
	printf("\n the number of nodes is %d \n",countnode(root));
	printf("\n the height of the tree is is %d \n",height(root));
	printf("\n the number of leaf nodes is %d \n",leafnodes(root));
	printf("\n the number of non-leaf nodes is %d \n",nonleaf(root));

	return 0;
}
