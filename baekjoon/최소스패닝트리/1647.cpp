#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int p[100001];

int getP(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = getP(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int selected = 0;
    int ans = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    int i;
    for (i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push({-z, {x, y}});
    }
    for (i = 0; i <= N; i++)
    {
        p[i] = i;
    }

    while (selected < N - 2 && !pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int c = -pq.top().first;
        pq.pop();

        if (getP(x) != getP(y))
        {
            p[p[x]] = p[y];
            selected += 1;
            ans += c;
        }
    }

    cout << ans << "\n";

    return 0;
}
