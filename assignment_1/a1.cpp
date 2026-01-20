#include <iostream>
using namespace std;

bool possible(int arr[], int n, int m, int limit)
{
    int parts = 1;        // number of segments
    int currentOR = 0;   // OR of current segment

    for (int i = 0; i < n; i++)
    {
        if ((currentOR | arr[i]) <= limit)
        {
            currentOR = currentOR | arr[i];
        }
        else
        {
            parts++;
            currentOR = arr[i];

            if (parts > m)
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int low = 0, high = 0;

    // find search range
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > low)
            low = arr[i];

        high = high | arr[i];
    }

    int answer = high;

    // binary search
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (possible(arr, n, m, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
