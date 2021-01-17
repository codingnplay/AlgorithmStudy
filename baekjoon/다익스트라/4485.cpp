#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool visited[125][125];
int board[125][125];
int dist[125][125];
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

#define INF 200625;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j;
    for (int t = 1;; t++)
    {
        cin >> N;
        if (N == 0)
            break;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                cin >> board[i][j];
                dist[i][j] = INF;
                visited[i][j] = false;
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        dist[0][0] = board[0][0];
        pq.push({-dist[0][0], {0, 0}});
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
                    if (dist[tx][ty] > d + board[tx][ty] && !visited[tx][ty])
                    {
                        dist[tx][ty] = d + board[tx][ty];
                        pq.push({-dist[tx][ty], {tx, ty}});
                    }
                }
            }
        }

        cout << "Problem " << t << ": " << dist[N - 1][N - 1] << "\n";
    }
    return 0;
}
