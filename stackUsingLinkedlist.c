#include <stdio.h>
#include <stdlib.h>

//struct to create node w data & pointer
struct node{
int info;
struct node* next;
}*top,*top1,*temp;

int count=0;

void push(int data){
if(top==NULL){
top=(struct node*)malloc(1*sizeof(struct node));
top->info=data;
top->next=NULL;
}
  else{
    temp=(struct node*)malloc(1*sizeof(struct node));
    temp->info=data;
    temp->next=top;
    top=temp;
  }
  count++;
  printf("Node inserted \n");
}

int pop(){
top1=top;
  if(top1=NULL){
    printf("\n Stack underflow \n");
    return -1;
  }
  else
    top1=top1->next;
  int popped=top->info;
  free(top);
  top=top1;
  count--;
  return popped;
}

void display(){
top1=top;
  if(top1==NULL){
    printf("\n Stack underflow \n");
    return;
  }
  printf("\n The stack is: \n");
  while(top1!=NULL){
    printf("%d-->",top1->info);
    top1=top1->next;
  }
  printf("NULL\n");
}

int main(){
int choice, value;
  printf("Implementation of Stack Using Linked list \n");
  while(1){
    printf("Enter required operation here: \n1. Push \n2. Pop \n3. Display \n4. Exit \n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the value to insert:");
        scanf("%d",&value);
        push(value);
        break;

      case 2:
        printf("\nPopped element is: %d", pop());
        break;

      case 3:
        display();
        break;

      case 4:
        exit(0);
        break;

      default:
        printf("Incorrect option selected\n");
    }
  }
}
