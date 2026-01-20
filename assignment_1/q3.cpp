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

    int sum = a[n-1] + a[n-2];
    cout << sum << endl;

    return 0;
}
