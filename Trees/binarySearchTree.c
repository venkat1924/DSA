#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *Node;

//if inorder is shown in ascending order, implies that traversal be true here worry not

void preorder(Node root){
	if(root!=NULL){
		printf("%d \t",root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}

void inorder(Node root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d \t",root->data);
		inorder(root->right);
	}	
}

void postorder(Node root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d \t",root->data);
	}	
}

Node createBST(Node root,int item){
	
	Node temp;
	temp=(Node)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
		return temp;
	
	if(item<root->data)
		root->left=createBST(root->left,item);    //damn cool recursive function to create 

	else
		root->right=createBST(root->right,item);

return root;
}

Node inordersuccessor(Node root){
	Node cur=root;
	while(cur->left!=NULL)
		cur=cur->left;
	return cur;
}

Node delete(Node root, int key){
	Node temp;
	if(root==NULL)
	return NULL;
	if(key<root->data)
			root->left=delete(root->left,key);
	else if(key>root->data) 							
			root->right=delete(root->right,key);
	else{
		if(root->left==NULL){
			temp=root->right;
			free(root);
			return temp;
		}
		
		if(root->right==NULL){
			temp=root->left;
			free(root);
			return temp;
		}
		temp=inordersuccessor(root->right);
		root->data=temp->data;
		root->right=delete(root->right,temp->data);
	}
		return root;
}

int main(){
	Node root=NULL;
	int item,choice,key;
	while(1){
		printf("Enter your choice here: \n 1.create \n 2.preorder \n 3.inorder \n 4.postorder \n 5.delete \n 6.exit \n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
			printf("type item to be sorted:");
			scanf("%d",&item);
			root=createBST(root,item);
			break;
			
			case 2:
			printf("\n the preorder traversal is: \n");
			preorder(root);
			break;
			
			case 3:
			printf("\n the inorder traversal is: \n");
			inorder(root);
			break;
			
			case 4:
			printf("\n the postorder traversal is: \n");
			postorder(root);
			break;
			
			case 5:
			printf("Input the element to be deleted from the binary search tree");
			scanf("%d",&key);
			root=delete(root,key);
			break;
			
			default:
			exit(0);
			
		}
	}
	
	return 0;
}
