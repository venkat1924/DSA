
#include <stdio.h>
#include <stdlib.h>

struct node{
    int ri;
    int ci;
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *Node;

Node insertend(Node start,int item, int row, int col){
    Node temp,cur;
    temp=(Node)malloc(sizeof(struct node));
    temp->ri=row;
    temp->ci=col;
    temp->data=item;
    temp->next=temp->prev=NULL;
    
    if(start==NULL)
        return temp;
        
    else{
    cur=start;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    
    return start;
    }
}

void display(Node start,int m,int n){
    int i,j;
    Node cur=start;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(cur->ri==i && cur->ci==j && cur->data!=0){
                printf("%d \t",cur->data);
                cur=cur->next;
            }
            else
            printf("0 \t");
        }
        printf("\n");
    }
}

int main(){
    int m=4,n=4;
    int i,j,item;
    Node start=NULL;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter value to %d row and %d column: ",i,j);
            scanf("%d",&item);
            if(item!=0)
                start=insertend(start,item,i,j);
        }
    }
    printf("The contents of the matrix are: \n");
   
    display(start,m,n);
    return 0;
}


