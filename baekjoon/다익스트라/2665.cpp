#include <iostream>
#include <queue>

using namespace std;

#define INF 3000

int N;
string board[50];
bool visited[50][50];
int dist[50][50];
priority_queue<pair<int, pair<int, int>>> pq;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    cin >> N;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
        for (j = 0; j < N; j++)
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
            if (tx >= 0 && ty >= 0 && tx < N && ty < N)
            {
                int w = board[tx][ty] == '0' ? 1 : 0;
                if (!visited[tx][ty] && dist[tx][ty] > d + w)
                {
                    dist[tx][ty] = d + w;
                    pq.push({-dist[tx][ty], {tx, ty}});
                }
            }
        }
    }

    cout << dist[N - 1][N - 1] << "\n";

    return 0;
}
