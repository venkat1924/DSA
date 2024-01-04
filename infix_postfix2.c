#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack{
    char s[20];
    int top;
    
};


void push(struct stack *st,char c){
    st->top++;
    st->s[st->top]=c;
}

char pop(struct stack *st){
    if(st->top==-1){
        printf("Error, stack underflow");
        return 0;
    }
    else{
    int temp;
    temp=st->s[st->top];
    st->top--;
    return temp;
    }
}


int precedence(int ch){
    switch(ch){
        case '^':
        return 3;
        break;
        
        case '*':
        case '/':
        return 2;
        break;
        
        case '+':
        case '-':
        return 1;
        break;
        
        default:
        return -1;
    }
}

int infixtopostfix(struct stack *st, char infix[20]){
    char postfix[20],symbol;
    int i,j=0;
    
    for(int i=0;infix[i]!='\0';i++){
        symbol=infix[i];
        if(isalnum(symbol)){
            postfix[j++]=symbol;
        }
        else{
            switch(symbol){
                case '(':
                push(st,symbol);
                break;
                
                case ')':
                while(st->s[st->top]!='(')
                    postfix[j++]=pop(st);
                    break;
            
                case '^':
                case '*':
                case '/':
                case '+':
                case '-':
                while((precedence(st->s[st->top])>=precedence(infix[i]))&&st->top!=-1){
                    postfix[j++]=pop(st);
                }
                push(st,symbol);
                break;
            }
        }
    }
    
    while(st->top!=-1)
            postfix[j++]=pop(st);
        postfix[j]='\0';
        printf("Postfix expression is: %s \n",postfix);
        return (1);
}

int main(){
    struct stack *s;
     s = (struct stack *)malloc(sizeof(struct stack)); 
    char infix[20];
    s->top=-1;
    printf("Enter infix expression");
    scanf("%s",infix);
    infixtopostfix(s,infix);
    free(s);
}
