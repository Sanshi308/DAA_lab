Q1.Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} and use Binary Search to find the target 23.

#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;          

        else if (arr[mid] < target)
            low = mid + 1;       

        else
            high = mid - 1;      
    }

    return -1; 
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 38, 56,23,72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout<<("Element %d found at index %d\n", target,result);
    else
        cout<<("Element not found\n");

    return 0;
}
