#include <iostream>
using namespace std;

int N;
int board[50][50];
bool rightOpen[50][50];
bool downOpen[50][50];
bool visited[50][50];
bool visited2[50][50];
int people;
int L, R;

void resetVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			visited2[i][j] = false;
		}
	}
}

bool check() {
	bool flag = false;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rightOpen[i][j] = false;
			downOpen[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N - 1 && abs(board[i][j] - board[i + 1][j]) >= L && abs(board[i][j] - board[i + 1][j]) <= R) {
				downOpen[i][j] = true;
				flag = true;
			}
			if (j < N - 1 && abs(board[i][j] - board[i][j + 1]) >= L && abs(board[i][j] - board[i][j + 1]) <= R) {
				rightOpen[i][j] = true;
				flag = true;
			}
		}
	}

	return flag;
}

int dfs_country(int i, int j) {
	visited[i][j] = true;

	int count = 1;
	people += board[i][j];
	if (i > 0 && !visited[i - 1][j] && downOpen[i - 1][j]) {
		count += dfs_country(i - 1, j);
	}
	if (j > 0 && !visited[i][j - 1] && rightOpen[i][j - 1]) {
		count += dfs_country(i, j - 1);
	}
	if (i < N - 1 && !visited[i + 1][j] && downOpen[i][j]) {
		count += dfs_country(i + 1, j);
	}
	if (j < N - 1 && !visited[i][j + 1] && rightOpen[i][j]) {
		count += dfs_country(i, j + 1);
	}
	return count;
}

void dfs_change_ppl(int i, int j, int ppl) {
	visited2[i][j] = true;
	board[i][j] = ppl;
	if (i > 0 && !visited2[i - 1][j] && downOpen[i - 1][j]) {
		dfs_change_ppl(i - 1, j, ppl);
	}
	if (j > 0 && !visited2[i][j - 1] && rightOpen[i][j - 1]) {
		dfs_change_ppl(i, j - 1, ppl);
	}
	if (i < N - 1 && !visited2[i + 1][j] && downOpen[i][j]) {
		dfs_change_ppl(i + 1, j, ppl);
	}
	if (j < N - 1 && !visited2[i][j + 1] && rightOpen[i][j]) {
		dfs_change_ppl(i, j + 1, ppl);
	}
}

int main()
{
	cin >> N >> L >> R;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;

	while (check()) {
		resetVisited();
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (!visited[i][j]) {
					people = 0;
					int country = dfs_country(i, j);
					if (country >= 2) {
						dfs_change_ppl(i, j, people / country);
					}
				}
			}
		}
		ans += 1;
		if (ans >= 2000) break;
	}

	cout << ans;

	return 0;
}
