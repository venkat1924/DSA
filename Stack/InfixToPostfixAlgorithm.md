# Algorithm: Infix to Postfix Conversion using Stacks

### Input:
- Infix expression

### Output:
- Postfix expression

### Steps:

1. Initialize an empty stack and an empty string for the output postfix expression.
2. Scan the infix expression from left to right.
3. For each symbol in the infix expression, do the following:
   - If the symbol is an operand (operand can be a digit or a letter), append it to the output postfix expression.
   - If the symbol is an opening parenthesis '(', push it onto the stack.
   - If the symbol is a closing parenthesis ')', pop elements from the stack and append them to the output postfix expression until an opening parenthesis '(' is encountered. Remove the opening parenthesis from the stack.
   - If the symbol is an operator (+, -, *, /, ^), then:
     - While the stack is not empty and the precedence of the operator at the top of the stack is greater than or equal to the precedence of the current operator, pop the operator from the stack and append it to the output postfix expression.
     - Push the current operator onto the stack.
4. After scanning the entire infix expression, pop any remaining operators from the stack and append them to the output postfix expression.
5. Return the postfix expression as the result.

### Example:

**Input:** (A + B) * (C - D)
<div align="center">
  
| Symbol | Stack | Postfix expression |
| ------ | ----- | ------------------ |
| (      | (     |                    |
| A      | (     | A                  |
| +      | ( +   | A                  |
| B      | ( +   | AB                 |
| )      |       | AB+                |
| *      | *     | AB+                |
| (      | *(    | AB+C               |
| C      | *(    | AB+C               |
| -      | *(-   | AB+C               |
| D      | *(-   | AB+CD              |
| )      | *     | AB+CD-             |
|        |       | AB+CD-*            |

</div>




**Output:** AB+CD-*

### Time Complexity:
- O(n), where n is the length of the infix expression.
