#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int board[10][10];
bool visited[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int p[10001];

int getp(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = getp(p[n]);
}

void dfs(int i, int j, int n)
{
    visited[i][j] = true;
    board[i][j] = n;
    for (int x = 0; x < 4; x++)
    {
        int nx = i + dx[x];
        int ny = j + dy[x];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && board[nx][ny] == 1)
            dfs(nx, ny, n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int n = 1;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                dfs(i, j, n);
                p[n] = n;
                n++;
            }
            //cout << board[i][j] << " ";
        }
        //cout << "\n";
    }
    //cout << "\n";

    priority_queue<pair<int, pair<int, int>>> pq;

    int x, y;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            int land1 = board[i][j];
            if (land1 != 0)
            {
                if (i < N - 1)
                {
                    for (x = i + 1; x < N; x++)
                    {
                        if (board[x][j] == land1)
                            break;
                        else if (board[x][j] != 0)
                        {
                            if ((x - i - 1) >= 2)
                            {
                                //cout << i << " " << j << " " << x << " " << j << " " << (x - i - 1) << "\n";
                                pq.push({-(x - i - 1), {land1, board[x][j]}});
                            }
                            break;
                        }
                    }
                }
                if (j < M - 1)
                {
                    for (y = j + 1; y < M; y++)
                    {
                        if (board[i][y] == land1)
                            break;
                        else if (board[i][y] != 0)
                        {
                            if ((y - j - 1) >= 2)
                            {
                                //cout << i << " " << j << " " << i << " " << y << " " << (y - j - 1) << "\n";
                                pq.push({-(y - j - 1), {land1, board[i][y]}});
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    int selected = 0;
    int ans = 0;

    while (selected < n - 2 && !pq.empty())
    {
        x = pq.top().second.first;
        y = pq.top().second.second;
        int c = -pq.top().first;
        pq.pop();

        if (getp(x) != getp(y))
        {
            p[p[x]] = p[y];
            selected += 1;
            ans += c;
        }
    }

    if (selected == n - 2)
        cout << ans << "\n";
    else
        cout << "-1\n";

    return 0;
}
