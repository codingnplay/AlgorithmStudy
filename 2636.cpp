#include <iostream>
#include <vector>
using namespace std;

int N, M, ans, days = 0;
int board[100][100];
bool visited[100][100];

void dfs(int x, int y) {
	visited[x][y] = true;

	if (board[x][y] == 0) {
		if (x > 0 && board[x - 1][y] == 0 && !visited[x - 1][y]) {
			dfs(x - 1, y);
		}
		if (y > 0 && board[x][y - 1] == 0 && !visited[x][y - 1]) {
			dfs(x, y - 1);
		}
		if (x < N - 1 && board[x + 1][y] == 0 && !visited[x + 1][y]) {
			dfs(x + 1, y);
		}
		if (y < M - 1 && board[x][y + 1] == 0 && !visited[x][y + 1]) {
			dfs(x, y + 1);
		}
		if (x > 0 && board[x - 1][y] == 1 && !visited[x - 1][y]) {
			dfs(x - 1, y);
		}
		if (y > 0 && board[x][y - 1] == 1 && !visited[x][y - 1]) {
			dfs(x, y - 1);
		}
		if (x < N - 1 && board[x + 1][y] == 1 && !visited[x + 1][y]) {
			dfs(x + 1, y);
		}
		if (y < M - 1 && board[x][y + 1] == 1 && !visited[x][y + 1]) {
			dfs(x, y + 1);
		}
	}
	else if (board[x][y] == 1) {
		board[x][y] = 2;
	}
}

bool check() {
	ans = 0;
	days += 1;
	int flag = true;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visited[i][j] = false;
			if (board[i][j] == 2) {
				ans += 1;
				board[i][j] = 0;
			}
			else if (board[i][j] == 1) flag = false;
		}
	}
	return flag;
}

int main()
{
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	do{
		dfs(0, 0);
	} while (!check());

	cout << days << "\n" << ans;

	return 0;
}
