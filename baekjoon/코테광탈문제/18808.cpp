#include <iostream>
#include <vector>

using namespace std;

int N, M, K, R, C;
bool Board[40][40];

class Sticker
{
public:
    int R, C;
    bool board[10][10];
    Sticker(int r, int c)
    {
        R = r;
        C = c;
    }
    void turnR()
    {
        bool tmp[10][10];
        int i, j;
        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C; j++)
            {
                tmp[j][R - i - 1] = board[i][j];
            }
        }
        int tp = R;
        R = C;
        C = tp;
        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C; j++)
            {
                board[i][j] = tmp[i][j];
            }
        }
    }
};

int countboard()
{
    int i, j, ans = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (Board[i][j])
                ans++;
        }
    }
    return ans;
}

void attach(Sticker s)
{
    int i, j, r, c, dir;
    for (dir = 0; dir < 4; dir++)
    {
        for (i = 0; i <= N - s.R; i++)
        {
            for (j = 0; j <= M - s.C; j++)
            {
                bool flag = true;
                for (r = 0; r < s.R; r++)
                {
                    for (c = 0; c < s.C; c++)
                    {
                        if (Board[i + r][j + c] && s.board[r][c])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
                if (flag)
                {
                    for (r = 0; r < s.R; r++)
                    {
                        for (c = 0; c < s.C; c++)
                        {
                            if (s.board[r][c])
                                Board[i + r][j + c] = true;
                        }
                    }
                    return;
                }
            }
        }
        s.turnR();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    int k, i, j, r, c;
    for (k = 0; k < K; k++)
    {
        cin >> r >> c;
        Sticker new_sticker(r, c);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cin >> new_sticker.board[i][j];
            }
        }
        attach(new_sticker);
    }

    cout << countboard() << "\n";

    return 0;
}
