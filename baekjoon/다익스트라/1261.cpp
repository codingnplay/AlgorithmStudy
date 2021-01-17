#include <iostream>
#include <queue>

using namespace std;

#define INF 20000

int N, M;
string board[100];
bool visited[100][100];
int dist[100][100];
priority_queue<pair<int, pair<int, int>>> pq;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    cin >> M >> N;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
        for (j = 0; j < M; j++)
        {
            dist[i][j] = INF;
        }
    }

    pq.push({-0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = -pq.top().first;
        pq.pop();

        if (dist[x][y] < d)
            continue;

        visited[x][y] = true;

        for (i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && ty >= 0 && tx < N && ty < M)
            {
                int w = board[tx][ty] == '0' ? 0 : 1;
                if (!visited[tx][ty] && dist[tx][ty] > d + w)
                {
                    dist[tx][ty] = d + w;
                    pq.push({-dist[tx][ty], {tx, ty}});
                }
            }
        }
    }

    cout << dist[N - 1][M - 1] << "\n";

    return 0;
}
