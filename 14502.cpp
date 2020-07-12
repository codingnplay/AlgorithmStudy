#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[8][8];
int cpyboard[8][8];
bool visited[8][8];

void cpy_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cpyboard[i][j] = board[i][j];
			visited[i][j] = false;
		}
	}
}

void dfs(int i, int j) {
	visited[i][j] = true;
	cpyboard[i][j] = 2;
	if (i < N-1 && cpyboard[i + 1][j] == 0 && !visited[i + 1][j]) {
		dfs(i + 1, j);
	}
	if (i > 0 && cpyboard[i - 1][j] == 0 && !visited[i - 1][j]) {
		dfs(i - 1, j);
	}
	if (j > 0 && cpyboard[i][j - 1] == 0 && !visited[i][j - 1]) {
		dfs(i, j - 1);
	}
	if (j < M-1 && cpyboard[i][j + 1] == 0 && !visited[i][j + 1]) {
		dfs(i, j + 1);
	}
}

int count0() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cpyboard[i][j] == 0) res += 1;
		}
	}
	return res;
}

int main()
{
	int i, j, k, l, m, n;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = i; k < N; k++) {
				for (l = 0; l < M; l++) {
					for (m = k; m < N; m++) {
						for (n = 0; n < M; n++) {
							if ((i != k || j != l) && (m != k || n != l) && (i != m || j != n) && board[i][j] == 0 && board[k][l] == 0 && board[m][n] == 0) {
								cpy_board();
								cpyboard[i][j] = 1;
								cpyboard[k][l] = 1;
								cpyboard[m][n] = 1;

								for (int x = 0; x < N; x++) {
									for (int y = 0; y < M; y++) {
										if (cpyboard[x][y] == 2 && !visited[x][y]) {
											dfs(x, y);
										}
									}
								}

								int tmp = count0();
								if (tmp > ans) ans = tmp;
							}
						}
					}
				}
			}
		}
	}

	cout << ans;

}
