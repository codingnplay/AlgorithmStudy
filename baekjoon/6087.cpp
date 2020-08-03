#include <iostream>
#include <list>

using namespace std;

int N, M;
bool visited[100][100];
int board[100][100];
list<pair<int, int>> BFSQueue;
int startX, startY;
int endX, endY;
int ans = 0;

void bfs() {
	if (BFSQueue.empty()) return;
	int x = BFSQueue.front().first;
	int y = BFSQueue.front().second;
	BFSQueue.pop_front();

	if (board[x][y] == -2) {
		endX = x;
		endY = y;
		board[x][y] = -1;
		return;
	}

	if (x > 0 && !visited[x - 1][y] && board[x - 1][y] != -1) {
		BFSQueue.push_back(make_pair(x - 1, y));
		visited[x - 1][y] = true;
		if (board[x - 1][y] != -2)
		board[x - 1][y] = board[x][y] + 1;
	}
	if (y > 0 && !visited[x][y - 1] && board[x][y - 1] != -1) {
		BFSQueue.push_back(make_pair(x, y - 1));
		visited[x][y - 1] = true;
		if (board[x][y - 1] != -2)
		board[x][y - 1] = board[x][y] + 1;
	}
	if (x < N - 1 && !visited[x + 1][y] && board[x + 1][y] != -1) {
		BFSQueue.push_back(make_pair(x + 1, y));
		if (board[x + 1][y] != -2)
		visited[x + 1][y] = true;
		board[x + 1][y] = board[x][y] + 1;
	}
	if (y < M - 1 && !visited[x][y + 1] && board[x][y + 1] != -1) {
		BFSQueue.push_back(make_pair(x, y + 1));
		visited[x][y + 1] = true;
		if (board[x][y + 1] != -2)
		board[x][y + 1] = board[x][y] + 1;
	}
	bfs();
}

int main()
{
	string str;
	int i, j;

	cin >> M >> N;
	for (i = 0; i < N; i++) {
		cin >> str;
		for (j = 0; j < M; j++) {
			if (str[j] == 'C') {
				board[i][j] = -2;
				startX = i; startY = j;
			}
			else if (str[j] == '*') {
				board[i][j] = -1;
			}
		}
	}

	BFSQueue.push_back(make_pair(startX, startY));
	visited[startX][startY] = true;
	board[startX][startY] = 0;
	bfs();

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	int minX, minY, minV;
	int predir = 0, dir;
	while (endX != startX || endY != startY) {
		minV = 100000;
		if (endX > 0 && board[endX - 1][endY] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX-1][endY] + 1)) {
			if (board[endX - 1][endY] < minV) {
				minV = board[endX - 1][endY]; minX = endX - 1; minY = endY;
				dir = 1;
			}
		}
		if (endY > 0 && board[endX][endY - 1] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX][endY - 1] + 1)) {
			if (board[endX][endY - 1] < minV) {
				minV = board[endX][endY - 1]; minX = endX; minY = endY - 1;
				dir = 2;
			}
		}
		if (endX < N - 1 && board[endX + 1][endY] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX + 1][endY] + 1)) {
			if (board[endX + 1][endY] < minV) {
				minV = board[endX + 1][endY]; minX = endX + 1; minY = endY;
				dir = 3;
			}
		}
		if (endY < M - 1 && board[endX][endY + 1] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX][endY + 1] + 1)) {
			if (board[endX][endY + 1] < minV) {
				minV = board[endX][endY + 1]; minX = endX; minY = endY + 1;
				dir = 4;
			}
		}
		if (predir == 1) {
			if (endX > 0 && board[endX - 1][endY] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX - 1][endY] + 1)) {
				if (board[endX - 1][endY] == minV) {
					minV = board[endX - 1][endY]; minX = endX - 1; minY = endY;
					dir = 1;
				}
			}
		}
		else if (predir == 2) {
			if (endY > 0 && board[endX][endY - 1] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX][endY - 1] + 1)) {
				if (board[endX][endY - 1] == minV) {
					minV = board[endX][endY - 1]; minX = endX; minY = endY - 1;
					dir = 2;
				}
			}
		}
		else if (predir == 3) {
			if (endX < N - 1 && board[endX + 1][endY] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX + 1][endY] + 1)) {
				if (board[endX + 1][endY] == minV) {
					minV = board[endX + 1][endY]; minX = endX + 1; minY = endY;
					dir = 3;
				}
			}
		}
		else {
			if (endY < M - 1 && board[endX][endY + 1] != -1 && (board[endX][endY] < 0 || board[endX][endY] == board[endX][endY + 1] + 1)) {
				if (board[endX][endY + 1] == minV) {
					minV = board[endX][endY + 1]; minX = endX; minY = endY + 1;
					dir = 4;
				}
			}
		}
		if (predir != dir) {
			ans++;
		}
		predir = dir;
		endX = minX; endY = minY;
	}

	cout << ans - 1;

	return 0;
}
