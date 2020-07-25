#include <iostream>
#include <vector>
using namespace std;

int N, M, days = 0;
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
	}
}

bool check() {
	days += 1;
	int flag = true;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visited[i][j] = false;
			if (board[i][j] == 2) {
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

	do {
		dfs(0, 0);

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (board[i][j] == 1) {
					int count = 0;
					if (board[i - 1][j] == 0 && visited[i - 1][j]) count += 1;
					if (board[i + 1][j] == 0 && visited[i + 1][j]) count += 1;
					if (board[i][j - 1] == 0 && visited[i][j - 1]) count += 1;
					if (board[i][j + 1] == 0 && visited[i][j + 1]) count += 1;
					if (count >= 2)	board[i][j] = 2;
				}
			}
		}
	} while (!check());

	cout << days << "\n";

	return 0;
}
