#include <stdio.h>
#include <ctype.h>

struct stack{
    char s[20];
    int top;
};

int precedence (char ch)
{
    switch(ch){
        case '^':return(5);break;
        case '/':
        case '*':return(3);break;
        case '+':
        case '-':return(1);
        default:return(0);
    }
}

int push(struct stack *st,char c)
{
    st->top+=1;
    st->s[st->top]=c;
    return(1);
}

int pop(struct stack *st)
{
    char temp;
    if(st->top==-1)
    {
        return 0;
    }
    else
    {
        temp=st->s[st->top];
        st->top-=1;
        return(temp);
    }
}

int in_to_post(char infix[20], struct stack *st)
{
    char postfix[20],symbol;
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        symbol=infix[i];
        if (isalnum(symbol))
        {
            postfix[j++]=symbol;
        }
        else{
            switch(symbol){
                case('('):push(st,symbol);break;
                case(')'):
                    while(st->s[st->top]!='(')
                    {
                        postfix[j++]=pop(st);
                    }
                    pop(st);
                    break;
                case('+'):
                case('-'):
                case('*'):
                case('/'):
                case('^'):
                    while(precedence(st->s[st->top])>=precedence(symbol) && st->top!=-1)
                    {
                        postfix[j++]=pop(st);
                    }
                    push(st,symbol);
                    break;
            }//switch
        }//else
    }//for

    while(st->top!=-1)
    {
        postfix[j++]=pop(st);
    }

    postfix[j++]='\0';
    printf("postfix expression= %s\n",postfix);
    return(1);
}

int main() {
    struct stack s;
    char infix[20];

    s.top=-1;
    printf("Enter infix expression: \n");
    scanf("%s", infix);
    in_to_post(infix,&s);
    return 0;
}
