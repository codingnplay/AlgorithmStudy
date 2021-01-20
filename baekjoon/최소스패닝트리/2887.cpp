#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int p[100001];
int N;

int getp(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = getp(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<pair<int, int>> xs;
    vector<pair<int, int>> ys;
    vector<pair<int, int>> zs;
    priority_queue<pair<long long, pair<int, int>>> pq;

    int i, x, y, z;
    for (i = 1; i <= N; i++)
    {
        cin >> x >> y >> z;
        xs.push_back({x, i});
        ys.push_back({y, i});
        zs.push_back({z, i});
        p[i] = i;
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    for (i = 0; i < N - 1; i++)
    {
        pq.push({-abs((long long)xs[i].first - xs[i + 1].first), {xs[i].second, xs[i + 1].second}});
        pq.push({-abs((long long)ys[i].first - ys[i + 1].first), {ys[i].second, ys[i + 1].second}});
        pq.push({-abs((long long)zs[i].first - zs[i + 1].first), {zs[i].second, zs[i + 1].second}});
    }

    int selected = 0;
    long long ans = 0;
    while (selected < N - 1)
    {
        x = pq.top().second.first;
        y = pq.top().second.second;
        long long c = -pq.top().first;
        pq.pop();

        if (getp(x) != getp(y))
        {
            p[p[x]] = p[y];
            selected += 1;
            ans += c;
        }
    }

    cout << ans << "\n";

    return 0;
}
