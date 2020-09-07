#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct node {
    int x; int y; int dist; bool broken;
};

int N, M;
string board[1000];
bool visited[1000][1000][2];
list<node> bfsQueue;
int tx[4] = { 0,0,-1,1 };
int ty[4] = { 1,-1,0,0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> board[i];
    }

    bfsQueue.push_back({ 0,0,1,false });
    visited[0][0][0] = true;

    while (!bfsQueue.empty()) {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int d = bfsQueue.front().dist;
        bool b = bfsQueue.front().broken;
        bfsQueue.pop_front();

        if (x == N - 1 && y == M - 1) {
            cout << d << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int mx = x + tx[k];
            int my = y + ty[k];

            if (mx >= 0 && my >= 0 && mx < N && my < M) {
                if (!b && !visited[mx][my][0] && board[mx][my] == '0') {
                    bfsQueue.push_back({ mx,my,d + 1,b });
                    visited[mx][my][0] = true;
                }
                else if (!b && !visited[mx][my][1] && board[mx][my] == '1') {
                    bfsQueue.push_back({ mx,my,d + 1,true });
                    visited[mx][my][1] = true;
                }
                else if (b && !visited[mx][my][1] && !visited[mx][my][0] && board[mx][my] == '0') {
                    bfsQueue.push_back({ mx,my,d + 1,b });
                    visited[mx][my][1] = true;
                }
            }
        }
    }

    cout << "-1\n";

    return 0;
}
