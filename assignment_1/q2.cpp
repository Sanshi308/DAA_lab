2.Implement Merge sort for the given array int arr[] = {12, 11, 13, 5, 6, 7}. After implementing Merge Sort, apply 
the same implementation to sort another array: int arr2[] = {38, 27, 43, 3, 9, 82, 10}.


#include <stdio.h>


void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSort(arr1, 0, size1 - 1);
    mergeSort(arr2, 0, size2 - 1);

    printf("Sorted arr1: ");
    printArray(arr1, size1);

    printf("Sorted arr2: ");
    printArray(arr2, size2);

    return 0;
}
