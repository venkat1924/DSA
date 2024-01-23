#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

struct queue {
	//struct members cant be declared in struct
	int front;
	int rear;
	char data[size][20];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q, char message[20]){
	if(q->front==(q->rear+1)%size)
		printf("Queue full");
	else{
		q->rear=q->rear+1;
		strcpy(q->data[q->rear],message);
	}
	if(q->front=-1)
		q->front=0;
}
 
char* dequeue(QUEUE *q){
	char *d;
	if(q->front==-1){
		printf("Queue empty \n");
		return NULL;
	}
	else{
		d=q->data[q->front];
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
		}
	else
		q->front=(q->front+1)%size;
	
	}
	return d;
}
void display(QUEUE q){
	int i;
	if(q.front==-1)
		printf("Queue is empty \n");
	else{
		printf("Queue contents are: \n");
		for(i=q.front;i!=q.rear;i=(i+1)%size){
			printf("%s \n",q.data[i]);
		}
		printf("%s \n",q.data[i]);
	}
}


int main(){
	QUEUE q;
	q.front =-1;
	q.rear =-1;
	int choice;
	char message[20];
	for(;;){
		printf("Enter option here: \n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit \n ");
		scanf("%d",&choice);
		getchar(); //so that enter doesnt screw up this program
		switch(choice){
			case 1:
			printf("\n Enter message to be enqueued:");
			gets(message);
			enqueue(&q,message);
			break;
			
			case 2:
			char *temp;
			temp = dequeue(&q);
			if(temp!=NULL)
				printf("the dequeued message is:%s \n",temp);
			
			break;
			
			case 3:
			display(q);
			break;
			
			default:
			exit(0);
		}
			// WHENEVER WE UPDATE A DATA STRUCTURE, USE A POINTER 
	}
		
}
