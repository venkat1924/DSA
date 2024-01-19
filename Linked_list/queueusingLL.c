#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node *Node;

Node InsertEnd(Node last, int item){
	Node temp;
	temp=(Node)malloc(sizeof(struct node));
	temp->data=item;
	if(last==NULL){
		temp->next=temp;
		return temp;
	}
	temp->next=last->next;
	last->next=temp;
	return temp;
}

Node DeleteBegin(Node last){
	if(last==NULL){
		printf("Underflow \n");
		return NULL;
	}
	if(last->next==last){
		printf("Deleted element is %d \n",last->data);
		free(last);
		return NULL;
	}
	Node temp;
	temp=last->next;
	printf("Element Deleted is %d \n",temp->data);
	last->next=temp->next;
	return last;
}
// why dafuck isnt display working correctly
void display(Node last){
	Node temp;
	if(last==NULL)
		printf("Empty Queue");
	else{
	for(temp=last->next;temp!=last;temp=temp->next){//print all elements from last->next to last->prev
	printf("%d \n",temp->data);
	}
	printf("%d \n", last->data);
	//print last
	}
}

int main(){
	Node last=NULL;
	int choice,item;
	while(1){
	printf("Enter the choice: \n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit \n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
		printf("Enter the element to be inserted \n");
		scanf("%d",&item);
		last=InsertEnd(last,item);
		break;
		
		case 2:
		DeleteBegin(last);
		break;
		
		case 3:
		display(last);
		break;
		
		case 4:
		exit (0);
		
		default:
		printf("Invalid choice. try again.");
		break;
	} 
	}
}
