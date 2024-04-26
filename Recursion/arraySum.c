#include <stdio.h>

int arraySum(int arr[], int n) 
{  
    if (n == 1) 
        return arr[0];
    else 
        return arr[n - 1] + arraySum(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    printf("Sum of elements in the array: %d\n", arraySum(arr, n));

    return 0;
}
