#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(a[j] > a[i])
                cnt++;
        }

        if(cnt >= k)
            sum += a[i];
    }

    cout << sum << endl;
    return 0;
}
