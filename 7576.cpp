#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int N, M;
int board[1001][1001];
bool visited[1001][1001];
int days = 1;
list<int> bfsQueueX;
list<int> bfsQueueY;

void bfs() {
	if (bfsQueueX.empty()) return;
	int x = bfsQueueX.front(); int y = bfsQueueY.front();
	bfsQueueX.pop_front(); bfsQueueY.pop_front();

	if (x > 0 && board[x - 1][y] == 0 && !visited[x - 1][y]) {
		board[x - 1][y] = board[x][y] + 1;
		visited[x - 1][y] = true;
		bfsQueueX.push_back(x - 1); bfsQueueY.push_back(y);
	}
	if (y > 0 && board[x][y - 1] == 0 && !visited[x][y - 1]) {
		board[x][y - 1] = board[x][y] + 1;
		visited[x][y - 1] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y - 1);
	}
	if (x < N - 1 && board[x + 1][y] == 0 && !visited[x + 1][y]) {
		board[x + 1][y] = board[x][y] + 1;
		visited[x + 1][y] = true;
		bfsQueueX.push_back(x + 1); bfsQueueY.push_back(y);
	}
	if (y < M - 1 && board[x][y + 1] == 0 && !visited[x][y + 1]) {
		board[x][y + 1] = board[x][y] + 1;
		visited[x][y + 1] = true;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y + 1);
	}

	bfs();
}

int main()
{
	int i, j;
	cin >> M >> N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			visited[i][j] = false;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				bfsQueueX.push_back(i);
				bfsQueueY.push_back(j);
				visited[i][j] = true;
			}
		}
	}

	bfs();

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				days = 0; i = N;
				break;
			}
			if (board[i][j] != -1 && board[i][j] > days) {
				days = board[i][j];
			}
		}
	}

	cout << days - 1;

	return 0;
}
