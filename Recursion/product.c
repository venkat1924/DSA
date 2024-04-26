#include <stdio.h>

int product(int a, int b) {
    // Base case: if either of the numbers is 0, product is 0
    if (a == 0 || b == 0) {
        return 0;
    }
    // Base case: if one of the numbers is 1, product is the other number
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    // Recursive case: add 'a' to the product of 'a' and 'b-1'
    return a + product(a, b - 1);
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = product(num1, num2);

    printf("Product of %d and %d is %d\n", num1, num2, result);

    return 0;
}
