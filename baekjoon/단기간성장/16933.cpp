#include <iostream>
#include <queue>

using namespace std;
int N, M, K;
bool visited[1000][1000][11];
string board[1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct node
{
    int t, x, y, day, broken;

    bool operator<(const node &a) const
    {
        return t > a.t;
    }
} node;

queue<node> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    pq.push({1, 0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!pq.empty())
    {
        int turn = pq.front().t;
        int x = pq.front().x;
        int y = pq.front().y;
        int day = pq.front().day;
        int broken = pq.front().broken;
        pq.pop();

        //cout << turn << " " << x << " " << y << " " << day << " " << broken << "\n";

        if (x == N - 1 && y == M - 1)
        {
            cout << turn << "\n";
            return 0;
        }

        int nextday = ((day == 1) ? 0 : 1);

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (board[nx][ny] == '0')
                {
                    if (!visited[nx][ny][broken])
                    {
                        pq.push({turn + 1, nx, ny, nextday, broken});
                        visited[nx][ny][broken] = true;
                    }
                }
                else // board[nx][ny] == '1'
                {
                    if (day == 1) //day
                    {
                        if (broken < K && !visited[nx][ny][broken + 1])
                        {
                            pq.push({turn + 1, nx, ny, nextday, broken + 1});
                            visited[nx][ny][broken + 1] = true;
                        }
                    } //night
                    else if (broken < K && !visited[nx][ny][broken + 1])
                    {
                        pq.push({turn + 1, x, y, nextday, broken});
                    }
                }
            }
        }
    }

    cout << "-1\n";

    return 0;
}
