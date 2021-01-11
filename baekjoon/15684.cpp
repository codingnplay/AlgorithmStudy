#include <iostream>

using namespace std;
bool origladder[11][31];
bool ladder[12][31];
int N, M, H;

bool check(int n)
{
    int x = n, y = 1;
    while (y <= M)
    {
        if (ladder[x][y])
        {
            x++;
        }
        else if (ladder[x - 1][y])
        {
            x--;
        }
        y++;
    }
    return x == n;
}

bool checkall()
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (!check(i))
            return false;
    }
    return true;
}

bool addladder(int n, int i, int j, int now)
{
    if (now == n)
    {
        if (checkall())
            return true;
        return false;
    }

    if (i < N)
    {
        i++;
    }
    else if (j < M)
    {
        i = 0;
        j++;
    }
    else
    {
        return false;
    }

    bool flag = false;
    if (i < N && !ladder[i][j] && !ladder[i + 1][j] && !ladder[i - 1][j])
    {
        ladder[i][j] = true;
        flag = addladder(n, i, j, now + 1);
        ladder[i][j] = false;
    }
    return flag || addladder(n, i, j, now);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H >> M;
    int i, x, y;
    for (i = 0; i < H; i++)
    {
        cin >> x >> y;
        ladder[y][x] = true;
    }

    for (i = 0; i <= 3; i++)
    {
        if (addladder(i, -1, 0, 0))
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
