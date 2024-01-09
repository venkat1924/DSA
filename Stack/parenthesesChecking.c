//The question from CIE 1.
//Write a C program to use a stack and check if an expression of parentheses is valid.
/* Example: (({[]{)) is valid
            (()[}} is invalid
            (({[})) is invalid     */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
   return top == -1;
}

bool isFull() {
   return top == MAX_SIZE - 1;
}

void push(char item) {
   if (isFull()) {
       printf("Stack Overflow\n");
       exit(1);
   }
   stack[++top] = item;
}

char pop() {
   if (isEmpty()) {
       printf("Stack Underflow\n");
       exit(1);
   }
   return stack[top--];
}

bool isMatchingPair(char opening, char closing) {
   return (opening == '(' && closing == ')') ||
          (opening == '{' && closing == '}') ||
          (opening == '[' && closing == ']');
}

bool areParenthesesValid(char *expr) {
   for (int i = 0; expr[i] != '\0'; i++) {
       char ch = expr[i];

       if (ch == '(' || ch == '{' || ch == '[') {
           // Push opening parenthesis onto the stack
           push(ch);
       } else if (ch == ')' || ch == '}' || ch == ']') {
           // Check for matching closing parenthesis
           if (isEmpty() || !isMatchingPair(pop(), ch)) {
               return false;
           }
       }
   }

   // If the stack is empty at the end, all parentheses are balanced
   return isEmpty();
}

int main() {
   char expression[MAX_SIZE];

   printf("Enter an expression: ");
   fgets(expression, MAX_SIZE, stdin);

   if (areParenthesesValid(expression)) {
       printf("Expression is valid\n");
   } else {
       printf("Expression is invalid\n");
   }

   return 0;
}

