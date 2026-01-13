You are given a 1D array that may contain both positive and negative integers, and find the sum of a contiguous subarray of numbers which has the largest sum. 
  For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        
        if (currentSum < 0)
            currentSum = arr[i];
        else
            currentSum += arr[i];

        
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxSubArraySum(arr, n);
    cout << "Maximum subarray sum = " << result << endl;

    return 0;
}
