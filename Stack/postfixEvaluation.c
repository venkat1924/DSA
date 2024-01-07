#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACKSIZE 20

struct stack
{
    int top;
    int items[STACKSIZE];
};

char pop(struct stack* ps)
{
    if (ps->top == -1) {
        printf("Underflow.\n");
        return -1; // Return an error value (-1) for invalid pop
    } else {
        return (ps->items[ps->top--]);
    }
}

void push(struct stack* ps, int value)
{
    if (ps->top == STACKSIZE - 1) {
        printf("Overflow.\n");
    } else {
        ps->items[++(ps->top)] = value;
    }
}

int postfix_evaluation(char postfix[20], struct stack* ps)
{
    int result = 0; // Initialize result to zero
    int operand1, operand2;
    char symbol;
    
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        
        if (isdigit(symbol)) {
            push(ps, symbol - '0'); // Convert char digit to int and push to stack
        } else {
            operand1 = pop(ps);
            operand2 = pop(ps);
            
            switch(symbol)
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand2 - operand1; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand2 / operand1; break;
                case '^': result = pow(operand2, operand1); break;
                default : printf("Invalid operator.\n"); exit(0);
            }
            
            push(ps, result); // Push the result back to the stack
        }
    }
    
    return pop(ps); // Return the final result
}

int main()
{
    char postfix[20];
    struct stack s;
    s.top = -1;
    
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    
    printf("Result = %d\n", postfix_evaluation(postfix, &s));
    return 0;
}
