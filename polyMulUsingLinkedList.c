#include <stdio.h>
#include <stdlib.h>

struct node{
  int ct; //coefficient of var
  int et; //exponent of var
struct node* next;
};
typedef struct node *Node;

void display(Node start){
  Node cur;
  if(start==NULL){
    printf("polynomial is empty \n");
    return;
  }
  cur=start;
  while(cur!=NULL){
    printf("%dX^%d \t", cur->ct,cur->et);
    cur=cur->next;
  }
}

Node insertend(Node start, int ct, int et){
  Node temp,cur;
  temp=(Node*)malloc(sizeof(struct node));
  temp->ct=ct;
  temp->et=et;
  temp->next=NULL;
  if(start==NULL)
    return temp;
  else{
    cur=start;
    while(cur->next!=NULL)
      cur=cur->next;
    cur->next=temp;
    return start;
  }
}

Node multiply(Node poly1, Node poly2){
Node cur1,cur2,result;
  result=NULL;
  for(cur1=poly1;cur1!=NULL;cur1=cur1->next){
    for(cur2=poly2;cur2!=NULL;cur2=cur2->next)
      result=insertend(result,cur1->ct*cur2->ct,cur1->et+cur2->et);
    return result;
  }
}

  int main(){
    Node first,second,result;
    int n1,n2,ct,et,i;
    first=NULL;
    second=NULL;
    printf("Enter total terms in polynomial 1 \n");
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
      printf("Enter coefficient terms and exponent terms for node %d \n",i+1);
      scanf("%d%d",&ct,&et);
        first=insertend(first,ct,et);
    }

     printf("Enter total terms in polynomial 2 \n");
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
      printf("Enter coefficient terms and exponent terms for node %d \n",i+1);
      scanf("%d%d",&ct,&et);
        first=insertend(first,ct,et);
    }
  result=multiply(first,second);
    printf("polynomial 1 = \n");
    display(first);
    printf("polynomial 2 = \n");
    display(second);
    printf("result = \n");
    display(result);
  }

