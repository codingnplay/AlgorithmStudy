#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
string board[50];
bool visited[50][50];
int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int getmaxd(int i, int j)
{
    int res = 0;
    visited[i][j] = true;
    queue<pair<pair<int, int>, int>> bfsQueue;
    bfsQueue.push({{i, j}, 0});
    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().first.first;
        int y = bfsQueue.front().first.second;
        int d = bfsQueue.front().second;
        res = max(res, d);
        bfsQueue.pop();

        for (int t = 0; t < 4; t++)
        {
            int tx = x + dx[t];
            int ty = y + dy[t];
            if (tx >= 0 && ty >= 0 && tx < N && ty < M && !visited[tx][ty] && board[tx][ty] == 'L')
            {
                visited[tx][ty] = true;
                bfsQueue.push({{tx, ty}, d + 1});
            }
        }
    }
    return res;
}

void reservisited()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    int i, j;
    int ans = 0;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (board[i][j] == 'L')
            {
                reservisited();
                ans = max(ans, getmaxd(i, j));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
