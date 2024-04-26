#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    if (num==1)
        return 1;
    else
        return num*factorial(num-1);
}

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("%d!=%d\n", num, factorial(num));
    return 0;
}
