Implement Quick Sort for arr[n] = { 4, 2, 6, 9, 2 }

#include <stdio.h>


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int P = low + 1;
    int Q = high;

    while (P <= Q)
    {
        while (P <= high && arr[P] <= pivot)
            P++;

        while (arr[Q] > pivot)
            Q--;

        if (P < Q)
        {
            int temp = arr[P];
            arr[P] = arr[Q];
            arr[Q] = temp;
        }
    }


    int temp = arr[low];
    arr[low] = arr[Q];
    arr[Q] = temp;

    return Q;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr, low, high);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 2, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
