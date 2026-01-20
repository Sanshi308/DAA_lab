#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int i = 0;
    int ans = 1;

    for(int j = 0; j < n; j++)
    {
        while(a[j] - a[i] > 10)
            i++;

        int len = j - i + 1;
        if(len > ans)
            ans = len;
    }

    cout << ans << endl;
    return 0;
}
