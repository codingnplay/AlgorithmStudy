#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int T, N, M, K;

#define INF 1000000000

struct route
{
    int dest, cost, time;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        cin >> N >> M >> K;
        int i, j;
        vector<vector<route>> edges(N + 1);
        for (i = 0; i < K; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            edges[u].push_back({v, c, d});
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        int dist[101][10001];
        for (i = 1; i <= N; i++)
            for (j = 0; j <= M; j++)
                dist[i][j] = INF;

        dist[1][0] = 0;
        pq.push({0, {1, 0}});
        while (!pq.empty())
        {
            int d = -pq.top().first;
            int now = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (dist[now][c] < d)
                continue;

            for (route edge : edges[now])
            {
                int next = edge.dest;
                int nextCost = c + edge.cost;
                int nextTime = d + edge.time;
                if (nextCost <= M && dist[next][nextCost] > nextTime)
                {
                    dist[next][nextCost] = nextTime;
                    pq.push({-nextTime, {next, nextCost}});
                }
            }
        }

        int ans = INF;
        for (i = 0; i <= M; i++)
            ans = min(ans, dist[N][i]);
        if (ans == INF)
            cout << "Poor KCM\n";
        else
            cout << ans << "\n";
    }

    return 0;
}
