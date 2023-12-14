#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int s[10];
    int top;
};

//Function prototypes
int push (struct stack* st, int item, int size);
int pop (struct stack* st, int size);
int display(struct stack* st);

int main()
{
    int choice, item, size;
    struct stack st;
    st.top=-1;
    printf("Enter the stack size: \n");
    scanf ("%d", &size);
    while(1)
    {
        printf("Enter choice, 1->Push, 2->Pop, 3->Display, 4->Exit:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to push: \n");
                    scanf("%d", &item);
                    if (push(&st, item, size))
                        printf("Pushed %d.\n", item);
                    break;
                    
            case 2: item = pop(&st, size);
                    if(item)
                        printf("Popped item is %d.\n", item);
                    break;
                    
            case 3: display(&st);
                    break;
                    
            case 4: exit(0);
                        
        }
    }
    return 1;
}

int push(struct stack* st, int item, int size)
{
    if (st->top==size-1)
    {
        printf("Stack overflow!");
        return (0);
    }
    else
    {
        st->top++;
        st->s[st->top]=item;
        return (1);
    }
}

int pop (struct stack* st, int size)
{
    int item;
    if(st->top == -1)
    {
        printf("Stack underflow!");
        return (0);
    }
    else
    {
        item = st->s[st->top];
        st->top--;
        return (item);
    }
}

int display (struct stack* st)
{
    int n;
    if (st->top==-1)
    {
        printf("Stack underflow!");
        return (0);
    }
    else
    {
        n=st->top;
        printf("Stack content: ");
        while(n>-1)
        {
            printf("%d, ", st->s[n]);
            n--;
        }
        printf("\n");
        return (1);
    }
}
