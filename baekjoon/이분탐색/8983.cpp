#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int M, N, L;
vector<int> s;
vector<pair<int, int>> a;

bool check(int n)
{
    int start = 0;
    int end = M - 1;
    int l = L - a[n].second;
    if (l < 0)
        return false;

    int low = a[n].first - l, high = a[n].first + l;
    while (start != end)
    {
        int middle = (start + end) / 2;
        if (s[middle] >= low && s[middle] <= high)
            return true;
        if (s[middle] > high)
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }

    return s[start] >= low && s[start] <= high;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> L;

    int i, x, y;
    for (i = 0; i < M; i++)
    {
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.begin() + M);
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }

    int ans = 0;

    for (i = 0; i < N; i++)
    {
        if (check(i))
            ans++;
    }
    cout << ans << "\n";

    return 0;
}
