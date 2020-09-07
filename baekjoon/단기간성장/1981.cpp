#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;

bool visited[100][100];
int board[100][100];
int mi = 200, ma = 0;
int ans = 200;
int N;
int tx[4] = { 0,1,-1,0 };
int ty[4] = { 1,0,0,-1 };
list<pair<int, int>> bfsQueue;

bool bfs(int left, int right) {

    while (!bfsQueue.empty()) {
        int i = bfsQueue.front().first;
        int j = bfsQueue.front().second;
        bfsQueue.pop_front();

        if (i == N - 1 && j == N - 1) return true;

        for (int x = 0; x < 4; x++) {
            int mx = i + tx[x];
            int my = j + ty[x];
            if (mx >= 0 && my >= 0 && mx < N && my < N && !visited[mx][my] && board[mx][my] >= left && board[mx][my] <= right) {
                bfsQueue.push_back({ mx,my });
                visited[mx][my] = true;
            }
        }
    }

    return false;
}

void solve(int left, int right) {

    if (left > right) return;

    int middle = (left + right) / 2;

    for (int i = mi; i <= ma - middle; i++) {
        if (board[0][0] >= i && board[0][0] <= i + middle){
            bfsQueue.clear();
            bfsQueue.push_back({ 0,0 });
            visited[0][0] = true;

            for (int m = 0; m < N; m++) {
                for (int n = 0; n < N; n++) {
                    visited[m][n] = false;
                }
            }
            if (bfs(i, i + middle)) {
                ans = middle;
                return solve(left, middle - 1);
            }
        }
    }
    solve(middle + 1, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] < mi) mi = board[i][j];
            if (board[i][j] > ma) ma = board[i][j];
        }
    }

    solve(0, ma - mi);
    cout << ans << "\n";
    
    return 0;
}
