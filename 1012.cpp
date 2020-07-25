#include <iostream>
#include <vector>

using namespace std;
int T, N, M, K;
int board[50][50];
bool visited[50][50];
vector<int> ans;

void dfs(int i, int j) {
	visited[i][j] = true;

	if (i > 0 && board[i - 1][j] && !visited[i - 1][j]) {
		dfs(i - 1, j);
	}
	if (j > 0 && board[i][j - 1] && !visited[i][j - 1]) {
		dfs(i, j - 1);
	}
	if (i < N - 1 && board[i + 1][j] && !visited[i + 1][j]) {
		dfs(i + 1, j);
	}
	if (j < M - 1 && board[i][j + 1] && !visited[i][j + 1]) {
		dfs(i, j + 1);
	}
}

int main()
{
	int i, j, t, x, y;
	cin >> T;

	for (t = 0; t < T; t++) {
		cin >> N >> M >> K;

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				board[i][j] = 0;
				visited[i][j] = false;
			}
		}

		for (i = 0; i < K; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}

		int count = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (board[i][j] && !visited[i][j]) {
					count++;
					dfs(i, j);
				}
			}
		}
		ans.push_back(count);
	}

	for (t = 0; t < T; t++) {
		cout << ans[t] << "\n";
	}

	return 0;
}
