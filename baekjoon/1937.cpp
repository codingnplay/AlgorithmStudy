#include <iostream>
#include <vector>
#include <list>

using namespace std;
int N;
int board[500][500];

int dp[500][500];
bool visited[500][500];
int ans = 0;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int dfs(int i, int j) {
	if (dp[i][j]) return dp[i][j];

	dp[i][j] = 1;
	if (i > 0 && board[i - 1][j] > board[i][j]) {
		dp[i][j] = max(dp[i][j], dfs(i - 1, j) + 1);
	}
	if (j > 0 && board[i][j - 1] > board[i][j]) {
		dp[i][j] = max(dp[i][j], dfs(i, j - 1) + 1);
	}
	if (i<N - 1 && board[i + 1][j]>board[i][j]) {
		dp[i][j] = max(dp[i][j], dfs(i + 1, j) + 1);
	}
	if (j<N - 1 && board[i][j + 1]>board[i][j]) {
		dp[i][j] = max(dp[i][j], dfs(i, j + 1) + 1);
	}
	return dp[i][j];
}

int main()
{
	cin >> N;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			ans = max(ans, dfs(i, j));
		}
	}

	cout << ans;

}
