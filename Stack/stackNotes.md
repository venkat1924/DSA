# Definition
Ordered collection of items into which new items may be inserted and from which items may be deleted at one end, called the top of the stack.
1) Stack is sometimes called a **last-in-first-out (LIFO) list** or a pushdown list.
2) The definition of a stack does not place an upper limit on the number of items in a stack, but the mode of implementation may.
# Stack Operations
1) **Push**: adds an item to the top of the stack.
2) **Empty**: determines whether a stack is empty.
3) **Pop**: removes the top element and returns it as a function value.
## Underflow
1) Result of an illegal attempt to pop or access an item from an empty stack.
2) No implementation of a stack will cure the underflow condition.
## Overflow
The possibility of overflow is introduced when a stack is implemented by an array with only a finite number of elements.
# Application of stacks
## Conversion of an infix expression to a postfix expression
- Initialize a stack and an empty string to store the postfix expression.
-  Scan the infix expression from left to right, symbol by symbol.
-  For each symbol:
    - If it's an operand (number, variable):
       - Append it directly to the postfix expression.
    - If it's an opening parenthesis '(':
       - Push it onto the stack.
    - If it's a closing parenthesis ')':
       - Pop operators from the stack and append them to the postfix expression until a matching '(' is found. Pop and discard the '('.
    - If it's an operator:
      - While the stack is not empty and the top of the stack has an operator with higher or equal precedence:
          - Pop the operator from the stack and append it to the postfix expression.
      - Push the current operator onto the stack.
- After scanning the entire expression:
    - Pop any remaining operators from the stack and append them to the postfix expression.
- The final string in the postfix expression variable is the converted expression.

### Precedence of operators (from highest to lowest):

1) Exponentiation (^)
2) Multiplication (*), Division (/)
3) Addition (+), Subtraction (-)
#### Additional notes:

1) Assumes valid infix expressions with balanced parentheses.
2) Consider error handling for invalid expressions.

## Evaluation of Postfix Expression using Stack

Create an empty stack to store operands.
Scan the postfix expression from left to right.
For each symbol:
If it's an operand:
Convert it to a number (if necessary) and push it onto the stack.
If it's an operator:
Pop the top two operands from the stack.
Perform the operation using the popped operands and the operator.
Push the result of the operation back onto the stack.
After scanning the entire expression, the final result will be the only item left on the stack.
Pop and return the final result.
## Example:

Postfix expression: 2 3 + 5 * 4 /

Steps:

Push 2 onto the stack.
Push 3 onto the stack.
Pop 3 and 2, add them (5), and push 5 onto the stack.
Push 5 onto the stack.
Push 4 onto the stack.
Pop 4 and 5, divide them (1), and push 1 onto the stack.
Pop 1 and 5, multiply them (5), and push 5 onto the stack.
The final result, 5, is on the stack.
## Key Points:

The order of operands in postfix expressions naturally dictates the order of operations.
A stack is well-suited for storing operands until their corresponding operators are encountered.
Operator precedence is not a concern in postfix evaluation.
Proper error handling should be implemented to address invalid expressions or stack underflow/overflow conditions.
