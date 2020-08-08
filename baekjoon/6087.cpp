#include <iostream>
#include <list>

using namespace std;
int N, M;
string board[100];
int D[100][100];
bool visited[100][100];
int startX, startY;
int endX, endY;
list<pair<int, int>> bfsQueue;
int ans = 999999;
int predir = 0;

void resetVisited(int n) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (D[i][j] <= n) {
				visited[i][j] = false;
			}
		}
	}
}

void bfs() {

	if (bfsQueue.empty()) return;
	int x = bfsQueue.front().first;
	int y = bfsQueue.front().second;
	bfsQueue.pop_front();

	if (D[x][y] != 1 && board[x][y] == 'C') {
		endX = x; endY = y;
		bfsQueue.clear();
		return;
	}

	if (x > 0 && !visited[x - 1][y] && board[x - 1][y] != '*') {
		bfsQueue.push_back(make_pair(x - 1, y));
		visited[x - 1][y] = true;
		D[x - 1][y] = D[x][y] + 1;
	}
	if (y > 0 && !visited[x][y - 1] && board[x][y - 1] != '*') {
		bfsQueue.push_back(make_pair(x, y - 1));
		visited[x][y - 1] = true;
		D[x][y - 1] = D[x][y] + 1;
	}
	if (x < N - 1 && !visited[x + 1][y] && board[x + 1][y] != '*') {
		bfsQueue.push_back(make_pair(x + 1, y));
		visited[x + 1][y] = true;
		D[x + 1][y] = D[x][y] + 1;
	}
	if (y < M - 1 && !visited[x][y + 1] && board[x][y + 1] != '*') {
		bfsQueue.push_back(make_pair(x, y + 1));
		visited[x][y + 1] = true;
		D[x][y + 1] = D[x][y] + 1;
	}
	bfs();
}

int dfs(int x, int y) {
	if (D[x][y] == 1) return 0;

	int res = 0;
	int ans = 999999;
	visited[x][y] = true;
	int depth = D[x][y];
	int tmpdir = predir;

	

	if (x > 0 && !visited[x - 1][y] && D[x - 1][y] == depth - 1) {
		if (tmpdir != 1) {
			res = 1;
		}
		else {
			res = 0;
		}
		predir = 1;
		res += dfs(x - 1, y);
		if (ans > res)ans = res;
		resetVisited(depth - 1);
	}
	if (y > 0 && !visited[x][y - 1] && D[x][y - 1] == depth - 1) {
		if (tmpdir != 2) {
			res = 1;
		}
		else {
			res = 0;
		}
		predir = 2;
		res += dfs(x, y - 1);
		if (ans > res)ans = res;
		resetVisited(depth - 1);
	}
	if (x < N - 1 && !visited[x + 1][y] && D[x + 1][y] == depth - 1) {
		if (tmpdir != 3) {
			res = 1;
		}
		else {
			res = 0;
		}
		predir = 3;
		res += dfs(x + 1, y);
		if (ans > res)ans = res;
		resetVisited(depth - 1);
	}
	if (y < M - 1 && !visited[x][y + 1] && D[x][y + 1] == depth - 1) {
		if (tmpdir != 4) {
			res = 1;
		}
		else {
			res = 0;
		}
		predir = 4;
		res += dfs(x, y + 1); 
		if (ans > res)ans = res;
		resetVisited(depth - 1);
	}

	return ans;
}

int main()
{
	cin >> M >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> board[i];
		for (j = 0; j < M; j++) {
			if (board[i][j] == 'C') {
				startX = i;
				startY = j;
			}
		}
	}

	D[startX][startY] = 1;
	visited[startX][startY] = true;
	bfsQueue.push_back(make_pair(startX, startY));
	bfs();

	resetVisited(D[endX][endY]);
	cout << dfs(endX, endY) - 1;

	return 0;
}
