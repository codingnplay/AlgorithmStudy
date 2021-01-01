#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;
int T;
int N, D, C;
int dist[10001];
vector<pair<int, int>> edges[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, x, y, z;
    cin >> T;

    for (i = 0; i < T; i++)
    {
        cin >> N >> D >> C;

        for (j = 1; j <= N; j++)
        {
            dist[j] = INF;
            edges[j].clear();
        }
        dist[C] = 0;

        priority_queue<pair<int, int>> pq;

        for (j = 0; j < D; j++)
        {
            cin >> x >> y >> z;
            edges[y].push_back({z, x});
        }
        pq.push({0, C});

        while (!pq.empty())
        {
            int d = -pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (dist[current] < d)
                continue;

            for (pair<int, int> v : edges[current])
            {
                if (dist[v.second] > d + v.first)
                {
                    dist[v.second] = d + v.first;
                    pq.push({-dist[v.second], v.second});
                }
            }
        }

        int count = 0;
        int time = 0;

        for (j = 1; j <= N; j++)
        {
            if (dist[j] != INF)
            {
                count++;
                if (time < dist[j])
                    time = dist[j];
            }
        }

        cout << count << " " << time << "\n";
    }

    return 0;
}
