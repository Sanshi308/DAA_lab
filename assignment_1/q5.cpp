#include <iostream>
using namespace std;

bool canFit(long long S, long long N, long long H, long long W)
{
    long long rows = S / H;
    long long cols = S / W;

    return (rows * cols >= N);
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = 0, high = 1e18, ans = 0;

        while(low <= high)
        {
            long long mid = (low + high) / 2;

            if(canFit(mid, N, H, W))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
