#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int N, M, H;
int board[101][101][101];
bool visited[101][101][101];
int days = 1;
list<int> bfsQueueX;
list<int> bfsQueueY;
list<int> bfsQueueZ;

void bfs() {
	if (bfsQueueX.empty()) return;
	int x = bfsQueueX.front(); int y = bfsQueueY.front(); int z = bfsQueueZ.front();
	bfsQueueX.pop_front(); bfsQueueY.pop_front(); bfsQueueZ.pop_front();

	if (x > 0 && board[x - 1][y][z] == 0 && !visited[x - 1][y][z]) {
		board[x - 1][y][z] = board[x][y][z] + 1;
		visited[x - 1][y][z] = true;
		bfsQueueX.push_back(x - 1); bfsQueueY.push_back(y); bfsQueueZ.push_back(z);
	}
	if (y > 0 && board[x][y - 1][z] == 0 && !visited[x][y - 1][z]) {
		board[x][y - 1][z] = board[x][y][z] + 1;
		visited[x][y - 1][z] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y - 1); bfsQueueZ.push_back(z);
	}
	if (z > 0 && board[x][y][z - 1] == 0 && !visited[x][y][z - 1]) {
		board[x][y][z - 1] = board[x][y][z] + 1;
		visited[x][y][z - 1] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y); bfsQueueZ.push_back(z - 1);
	}
	if (x < N - 1 && board[x + 1][y][z] == 0 && !visited[x + 1][y][z]) {
		board[x + 1][y][z] = board[x][y][z] + 1;
		visited[x + 1][y][z] = true;
		bfsQueueX.push_back(x + 1); bfsQueueY.push_back(y); bfsQueueZ.push_back(z);
	}
	if (y < M - 1 && board[x][y + 1][z] == 0 && !visited[x][y + 1][z]) {
		board[x][y + 1][z] = board[x][y][z] + 1;
		visited[x][y + 1][z] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y + 1); bfsQueueZ.push_back(z);
	}
	if (z < H - 1 && board[x][y][z + 1] == 0 && !visited[x][y][z + 1]) {
		board[x][y][z + 1] = board[x][y][z] + 1;
		visited[x][y][z + 1] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y); bfsQueueZ.push_back(z + 1);
	}

	bfs();
}

int main()
{
	int i, j, k;
	cin >> M >> N >> H;

	for (k = 0; k < H; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				cin >> board[i][j][k];
				visited[i][j][k] = false;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < H; k++) {
				if (board[i][j][k] == 1) {
					bfsQueueX.push_back(i);
					bfsQueueY.push_back(j);
					bfsQueueZ.push_back(k);
					visited[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < H; k++) {
				if (board[i][j][k] == 0) {
					days = 0; i = N; j = M;
					break;
				}
				if (board[i][j][k] != -1 && board[i][j][k] > days) {
					days = board[i][j][k];
				}
			}
		}
	}

	cout << days - 1;

	return 0;
}
