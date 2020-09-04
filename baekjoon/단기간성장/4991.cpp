#include <iostream>
#include <list>
using namespace std;

struct node {
    int x;
    int y;
    int curCnt;
    int curDust;
};

int N, M;
bool visited[20][20][1 << 11];
char board[20][20];
list<node> bfsQueue;

int countBit(int n) {
    if (n == 0) {
        return 0;
    }
    else return n % 2 + countBit(n / 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string tmp;
    int i, j;
    int startX, startY;
    int dustCnt = 0;
    int dust = 'a';
    int mx[4] = { 0,0,1,-1 };
    int my[4] = { 1,-1,0,0 };
    
    while (1) {
        cin >> M >> N;
        if (N == 0 && M == 0) {
            break;
        }

        dustCnt = 0;
        dust = 'a';

        for (i = 0; i < N; i++) {
            cin >> tmp;
            for (j = 0; j < M; j++) {
                board[i][j] = tmp[j];
                if (board[i][j] == 'o') {
                    startX = i; startY = j;
                }
                else if (board[i][j] == '*') {
                    board[i][j] = dust;
                    dust++;
                    dustCnt++;
                }
            }
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                for (int k = 0; k < 1 << dustCnt + 1; k++) {
                    visited[i][j][k] = false;
                }
            }
        }

        bfsQueue.clear();
        bfsQueue.push_back({startX, startY, 0, 0});
        visited[startX][startY][0] = true;
        board[startX][startY] = '.';

        int ans = -1;

        while (!bfsQueue.empty()) {
            i = bfsQueue.front().x;
            j = bfsQueue.front().y;
            int Cnt = bfsQueue.front().curCnt;
            int curDust = bfsQueue.front().curDust;
            bfsQueue.pop_front();

            if (countBit(curDust) == dustCnt) {
                ans = Cnt;
                break;
            }

            for (int x = 0; x < 4; x++) {
                int tx = i + mx[x];
                int ty = j + my[x];
                if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
                    if (board[tx][ty] == 'x') {
                        ;
                    }
                    else if (board[tx][ty] == '.' && !visited[tx][ty][curDust]) {
                        visited[tx][ty][curDust] = true;
                        bfsQueue.push_back({ tx, ty, Cnt + 1, curDust });
                    }
                    else if (board[tx][ty] >= 'a' && board[tx][ty] < 'o' && !visited[tx][ty][curDust]) {
                        visited[tx][ty][curDust] = true;
                        visited[tx][ty][curDust | (1 << (board[tx][ty] - 'a'))] = true;
                        bfsQueue.push_back({ tx, ty, Cnt + 1, curDust | (1 << (board[tx][ty] - 'a')) });
                    }
                }
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}
