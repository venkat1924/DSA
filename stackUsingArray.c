#include <stdio.h>
#include <stdbool.h>

//global variables
int stack[20], size, item, top=-1; 

//function prototypes
int push(int item);
int pop();
int display();


int main()
{
    int choice;
    
    while(1)
    {
        printf("Enter size of the stack: \n");
        scanf("%d", &size);
        if (size>20)
            printf("Too big, enter size up till 20");
        else
            break;
    }
    
    while(1)
    {
        printf("Enter choice, 1->Push, 2->Pop, 3->Display, 4->Exit:\n");
        scanf("%d", &choice);
        
        if(choice == 4)
        {
            printf("Exiting program.\n");
            break;
        }
            
        
        switch(choice)
        {
            case 1: 
                printf("Enter item to push:\n");
                scanf("%d", &item);
                choice=push(item);
                if(choice)
                    printf("Successfully pushed %d to the stack.\n", item);
                else
                    printf("Stack overflow!%d", choice);
                break;
                
            case 2:
                if((item = pop()) != false)
                    printf("Successfully removed %d from the top of the stack.\n", item);
                else
                    printf("Stack underflow!");
                break;
                
            case 3:
                if(!display())
                    printf("Stack is empty.");
                    break;

            default:
                printf("Invalid choice.");
        }
    }
}

int push (int item)
{
    if (top == (size-1))
        return 0;
    else
    {
        ++top;
        stack[top]=item;
        return 1;
    }
}

int pop()
{
    if (top==-1)
        return false;
    else
    {
        item = stack[top];
        --top;
        return item;
    }
}

int display()
{
    if (top==-1)
        return 0;
    else
    {
        for (int i=0; i<=top;i++)
            printf("%d ", stack[i]);
        printf("\n");
        return 1;
    }
}