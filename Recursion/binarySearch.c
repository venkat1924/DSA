#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        return binarySearch(arr, mid + 1, high, target);
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) 
        printf("Element is not present in array\n") 
    else
        printf("Element is present at index %d\n", result);
        
    return 0;
}
