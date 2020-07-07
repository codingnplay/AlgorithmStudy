#include <iostream>
#include <list>

using namespace std;

list<int> bfsQueueX;
list<int> bfsQueueY;
int N, M;
int board[101][101];
bool visited[101][101];

void bfs() {
	if (bfsQueueX.empty()) return;

	int x = bfsQueueX.front();
	int y = bfsQueueY.front();
	bfsQueueX.pop_front(); bfsQueueY.pop_front();

	int level = board[x][y];

	if (x > 0 && board[x - 1][y] == 1 && !visited[x - 1][y]) {
		visited[x - 1][y] = true;
		board[x - 1][y] = level + 1;
		bfsQueueX.push_back(x - 1); bfsQueueY.push_back(y);
	}
	if (y > 0 && board[x][y - 1] == 1 && !visited[x][y - 1]) {
		visited[x][y - 1] = true;
		board[x][y - 1] = level + 1;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y - 1);
	}
	if (x < N - 1 && board[x + 1][y] == 1 && !visited[x + 1][y]) {
		visited[x + 1][y] = true;
		board[x + 1][y] = level + 1;
		bfsQueueX.push_back(x + 1); bfsQueueY.push_back(y);
	}
	if (y < M - 1 && board[x][y + 1] == 1 && !visited[x][y + 1]) {
		visited[x][y + 1] = true;
		board[x][y + 1] = level + 1;
		bfsQueueX.push_back(x); bfsQueueY.push_back(y + 1);
	}

	bfs();
}

int main()
{
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (j = 0; j < M; j++) {
			visited[i][j] = false;
			if (tmp[j] == '0') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}

	bfsQueueX.push_back(0);
	bfsQueueY.push_back(0);
	visited[0][0] = true;
	bfs();

	cout << board[N - 1][M - 1];
}
