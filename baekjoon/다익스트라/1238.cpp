#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 10000000

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, S, i, x, y, z;
    cin >> N >> M >> S;
    vector<vector<pair<int, int>>> edges(N + 1);
    vector<vector<pair<int, int>>> edges2(N + 1);
    vector<int> dist(N + 1);
    vector<int> dist2(N + 1);
    fill(dist.begin(), dist.begin() + N + 1, INF);
    fill(dist2.begin(), dist2.begin() + N + 1, INF);
    dist[S] = 0;
    dist2[S] = 0;
    for (i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
        edges2[y].push_back({z, x});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        int d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if (dist[x] < d)
            continue;
        for (pair<int, int> edge : edges[x])
        {
            if (dist[edge.second] > d + edge.first)
            {
                dist[edge.second] = d + edge.first;
                pq.push({dist[edge.second], edge.second});
            }
        }
    }
    pq.push({0, S});
    while (!pq.empty())
    {
        int d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if (dist2[x] < d)
            continue;
        for (pair<int, int> edge : edges2[x])
        {
            if (dist2[edge.second] > d + edge.first)
            {
                dist2[edge.second] = d + edge.first;
                pq.push({dist2[edge.second], edge.second});
            }
        }
    }
    int ans = 0;
    for (i = 1; i <= N; i++)
    {
        if (ans < dist[i] + dist2[i])
            ans = dist[i] + dist2[i];
    }
    cout << ans << "\n";
    return 0;
}
