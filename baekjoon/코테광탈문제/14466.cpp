#include <iostream>
#include <vector>

using namespace std;

int N, K, R;
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> edges[101][101];
pair<int, int> cow[101];

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx > 0 && ty > 0 && tx <= N && ty <= N && !visited[tx][ty])
        {
            bool flag = true;
            for (pair<int, int> e : edges[x][y])
            {
                if (e.first == tx && e.second == ty)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                dfs(tx, ty);
        }
    }
}

void resetVisited()
{
    int i, j;
    for (i = 0; i <= N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> R;
    int r, r2, c, c2;

    int i, j;
    int ans = 0;
    for (i = 0; i < R; i++)
    {
        cin >> r >> c >> r2 >> c2;
        edges[r][c].push_back({r2, c2});
        edges[r2][c2].push_back({r, c});
    }

    for (i = 0; i < K; i++)
    {
        cin >> cow[i].first >> cow[i].second;
    }

    for (i = 0; i < K; i++)
    {
        resetVisited();
        dfs(cow[i].first, cow[i].second);
        for (j = i + 1; j < K; j++)
        {
            if (!visited[cow[j].first][cow[j].second])
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
