#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1999999999

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, x, y, z, i, S, E;
    cin >> N >> M;

    vector<vector<pair<int, int>>> edges(N + 1);
    vector<int> dist(N + 1);

    for (i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
    }

    cin >> S >> E;

    fill(dist.begin(), dist.begin() + N + 1, INF);
    dist[S] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, S});

    while (!pq.empty())
    {
        int d = pq.top().first;
        x = pq.top().second;
        pq.pop();

        if (d > dist[x])
            continue;

        for (pair<int, int> e : edges[x])
        {
            if (dist[e.second] > d + e.first)
            {
                dist[e.second] = d + e.first;
                pq.push({dist[e.second], e.second});
            }
        }
    }

    cout << dist[E] << "\n";

    return 0;
}
