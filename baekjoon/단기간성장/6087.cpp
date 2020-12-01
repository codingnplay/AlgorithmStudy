#include <iostream>
#include <queue>
using namespace std;

int W, H;
int startX, startY;
char board[100][100];
bool visited[100][100];
int laser[100][100];
queue<pair<int, int>> bfsQueue;

int main()
{
    cin >> W >> H;

    string tmp;
    int i, j;

    for (i = 0; i < H; i++) {
        cin >> tmp;
        for (j = 0; j < W; j++) {
            board[i][j] = tmp[j];
            if (tmp[j] == 'C') {
                startX = i;
                startY = j;
            }
        }
    }

    bfsQueue.push({ startX, startY });
    visited[startX][startY] = true;

    while (!bfsQueue.empty()) {
        pair<int, int> front = bfsQueue.front();
        bfsQueue.pop();

        int x = front.first;
        int y = front.second;

        //cout << x << " " << y << " " << laser[x][y] << "\n";

        if((x!=startX || y!=startY) && board[x][y] == 'C'){
            cout << laser[x][y] - 1 << "\n";
            break;
        }
        
        for (i = y-1; i >= 0; i--) {
            if (board[x][i] == '*')
                break;
            if (!visited[x][i]) {
                laser[x][i] = laser[x][y] + 1;
                visited[x][i] = true;
                bfsQueue.push({ x,i });
            }
        }

        for (i = y + 1; i < W; i++) {
            if (board[x][i] == '*')break;
            if (!visited[x][i]) {
                laser[x][i] = laser[x][y] + 1;
                visited[x][i] = true;
                bfsQueue.push({ x,i });
            }
        }

        for (i = x-1; i >= 0; i--) {
            if (board[i][y] == '*')break;
            if (!visited[i][y]) {
                laser[i][y] = laser[x][y] + 1;
                visited[i][y] = true;
                bfsQueue.push({ i,y });
            }
        }

        for (i = x + 1; i < H; i++) {
            if (board[i][y] == '*') break;
            if (!visited[i][y]) {
                laser[i][y] = laser[x][y] + 1;
                visited[i][y] = true;
                bfsQueue.push({ i,y });
            }
        }
    }

    return 0;
}
