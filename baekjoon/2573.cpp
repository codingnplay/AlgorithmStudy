#include <iostream>
#include <vector>
#include <list>

using namespace std;

int N, M;
int board[300][300];
bool visited[300][300];

void dfs(int i, int j) {
	visited[i][j] = true;

	if (board[i - 1][j] != 0 && !visited[i - 1][j]) dfs(i - 1, j);
	if (board[i][j - 1] != 0 && !visited[i][j - 1]) dfs(i, j - 1);
	if (board[i + 1][j] != 0 && !visited[i + 1][j]) dfs(i + 1, j);
	if (board[i][j + 1] != 0 && !visited[i][j + 1]) dfs(i, j + 1);
}

int get_count_dfs() {
	
	int count = 0;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	for (i = 1; i < N - 1; i++) {
		for (j = 1; j < M - 1; j++) {
			if (board[i][j] != 0 && !visited[i][j]) {
				count++;
				dfs(i, j);
			}
		}
	}

	return count;
}

bool melt() {

	int i, j;
	bool flag = false;
	int tmp[300][300];

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			tmp[i][j] = board[i][j];
		}
	}

	for (i = 1; i < N - 1; i++) {
		for (j = 1; j < M - 1; j++) {
			if (board[i][j] != 0) {
				flag = true;
				int mcount = 0;
				if (tmp[i - 1][j] == 0) mcount++;
				if (tmp[i][j - 1] == 0) mcount++;
				if (tmp[i + 1][j] == 0) mcount++;
				if (tmp[i][j + 1] == 0) mcount++;
				board[i][j] -= mcount;
				if (board[i][j] < 0) board[i][j] = 0;
			}
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

	int sec = 0;
	while (get_count_dfs() < 2) {
		if (melt()) sec++;
		else {
			sec = 0;
			break;
		}
	}
	cout << sec;
}
