#include <iostream>
#include <queue>
using namespace std;

int N, startX = -1, startY, endX, endY;
char board[50][50];
int tx[4] = { 0,0,1,-1 };
int ty[4] = { 1,-1,0,0 };
int mirror[50][50];
bool visited[50][50];
queue<pair<int,int>> bfsQueue;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int i, j;
	string tmp;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		for (j = 0; j < N; j++) {
			board[i][j] = tmp[j];
			if (board[i][j] == '#') {
				if (startX == -1) {
					startX = i; startY = j;
				}
				else {
					endX = i; endY = j;
				}
			}
		}
	}

	visited[startX][startY] = true;
	mirror[startX][startY] = 0;
	bfsQueue.push({ startX,startY });

	while (!bfsQueue.empty()) {
		int x = bfsQueue.front().first; 
		int y = bfsQueue.front().second;
		bfsQueue.pop();

		if (board[x][y] == '#' && x != startX && y != startY) break;

		if (board[x][y] != '.') {
			for (i = x + 1; i < N; i++) {
				if (board[i][y] == '*') break;
				if (!visited[i][y]) {
					visited[i][y] = true;
					mirror[i][y] = mirror[x][y] + 1;
					bfsQueue.push({ i,y });
				}
			}
			for (i = x - 1; i >= 0; i--) {
				if (board[i][y] == '*') break;
				if (!visited[i][y]) {
					visited[i][y] = true;
					mirror[i][y] = mirror[x][y] + 1;
					bfsQueue.push({ i,y });
				}
			}
			for (i = y + 1; i < N; i++) {
				if (board[x][i] == '*') break;
				if (!visited[x][i]) {
					visited[x][i] = true;
					mirror[x][i] = mirror[x][y] + 1;
					bfsQueue.push({ x,i });
				}
			}
			for (i = y - 1; i >= 0; i--) {
				if (board[x][i] == '*') break;
				if (!visited[x][i]) {
					visited[x][i] = true;
					mirror[x][i] = mirror[x][y] + 1;
					bfsQueue.push({ x,i });
				}
			}
		}
	}

	cout << mirror[endX][endY] - 1;

	return 0;
}
