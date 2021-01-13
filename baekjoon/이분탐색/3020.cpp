#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, H, i;

    cin >> N >> H;

    vector<int> bottom(N / 2), top(N / 2);

    for (i = 0; i < N / 2; i++)
    {
        cin >> bottom[i] >> top[i];
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int ans = 200001, count = 0;

    for (i = 1; i <= H; i++)
    {
        int x = N / 2 - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        x += N / 2 - (upper_bound(top.begin(), top.end(), H - i) - top.begin());
        if (ans > x)
        {
            ans = x;
            count = 1;
        }
        else if (ans == x)
            count++;
    }
    cout << ans << " " << count << "\n";
    return 0;
}
