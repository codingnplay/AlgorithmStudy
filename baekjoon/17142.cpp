#include <iostream>
#include <cmath>
#include <list>
#include <vector>

using namespace std;
char board[50][50];
bool visited[50][50];
int N, M;
int ans = 2500;
vector<pair<int, int>> v;
bool include[11];
list<pair<pair<int, int>, int>> bfsQueue;

bool checkVirusSpread()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] == '0' && !visited[i][j])
                return false;
        }
    }
    return true;
}

void resetVisited()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int brute(int n, int selected)
{
    if (selected == M)
    {
        resetVisited();
        bfsQueue.clear();
        for (int i = 0; i < 11; i++)
        {
            if (include[i])
            {
                bfsQueue.push_front({{v[i].first, v[i].second}, 0});
            }
        }

        int time = 0;

        while (!bfsQueue.empty())
        {
            int x = bfsQueue.front().first.first;
            int y = bfsQueue.front().first.second;
            int t = bfsQueue.front().second;
            bfsQueue.pop_front();

            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx >= 0 && ty >= 0 && tx < N && ty < N && board[tx][ty] != '1' && !visited[tx][ty])
                {
                    if (board[tx][ty] == '0')
                        time = max(time, t + 1);
                    bfsQueue.push_back({{tx, ty}, t + 1});
                    visited[tx][ty] = true;
                }
            }
        }

        if (checkVirusSpread())
            return time;
        else
            return 5000;
    }

    if (n + 1 >= v.size())
        return 5000;

    int res = 5000;
    include[n + 1] = true;
    res = min(res, brute(n + 1, selected + 1));
    include[n + 1] = false;
    res = min(res, brute(n + 1, selected));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j;
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '2')
                v.push_back({i, j});
        }
    }

    int ans = 5000;
    include[0] = true;
    ans = min(ans, brute(0, 1));
    include[0] = false;
    ans = min(ans, brute(0, 0));

    if (ans == 5000)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
