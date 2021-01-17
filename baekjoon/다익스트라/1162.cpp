#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
int N, M, K;

#define INF 50000000001
ll dist[10001][21];
vector<pair<ll, ll>> edges[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    int i, j;
    for (i = 0; i < M; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
        edges[y].push_back({z, x});
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j <= K; j++)
        {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        int now = pq.top().second.first;
        ll d = -pq.top().first;
        int nk = pq.top().second.second;
        pq.pop();

        if (dist[now][nk] < d)
            continue;

        for (pair<ll, ll> edge : edges[now])
        {
            ll next = edge.second;
            ll nextCost = d + edge.first;
            if (dist[next][nk] > nextCost)
            {
                dist[next][nk] = nextCost;
                pq.push({-nextCost, {next, nk}});
            }
            if (nk < K && dist[next][nk + 1] > d)
            {
                dist[next][nk + 1] = d;
                pq.push({-d, {next, nk + 1}});
            }
        }
    }

    ll ans = INF;
    for (i = 0; i <= K; i++)
    {
        ans = min(dist[N][i], ans);
    }
    cout << ans << "\n";
    return 0;
}
