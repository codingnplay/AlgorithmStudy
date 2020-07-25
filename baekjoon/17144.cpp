#include <iostream>
using namespace std;

int N, M, T;
int board[51][51];
int cpyboard[51][51];
int puriX;

void cpy_board() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cpyboard[i][j] = board[i][j];
		}
	}
}

void spread() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cpyboard[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (board[i][j] > 0) {
				int tmp = board[i][j] / 5;
				if (i > 0 && board[i - 1][j] != -1) {
					cpyboard[i - 1][j] += tmp;
					cpyboard[i][j] -= tmp;
				}
				if (j > 0 && board[i][j - 1] != -1) {
					cpyboard[i][j - 1] += tmp;
					cpyboard[i][j] -= tmp;
				}
				if (i < N - 1 && board[i + 1][j] != -1) {
					cpyboard[i + 1][j] += tmp;
					cpyboard[i][j] -= tmp;
				}
				if (j < M - 1) {
					cpyboard[i][j + 1] += tmp;
					cpyboard[i][j] -= tmp;
				}
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			board[i][j] += cpyboard[i][j];
		}
	}
}

void purify() {
	int i, j;
	cpy_board();
	cpyboard[puriX - 1][1] = 0; cpyboard[puriX][1] = 0;
	for (i = M - 1; i >= 2; i--) {
		cpyboard[puriX - 1][i] = board[puriX - 1][i - 1];
		cpyboard[puriX][i] = board[puriX][i - 1];
	}
	for (i = 0; i <= puriX - 2; i++) {
		cpyboard[i][M - 1] = board[i + 1][M - 1];
	}
	for (i = 0; i < M - 1; i++) {
		cpyboard[0][i] = board[0][i + 1];
		cpyboard[N - 1][i] = board[N - 1][i + 1];
	}
	for (i = puriX - 2; i >= 1; i--) {
		cpyboard[i][0] = board[i - 1][0];
	}
	for (i = N - 1; i > puriX; i--) {
		cpyboard[i][M - 1] = board[i - 1][M - 1];
	}
	for (i = puriX + 1; i < N - 1; i++) {
		cpyboard[i][0] = board[i + 1][0];
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			board[i][j] = cpyboard[i][j];
		}
	}
}

int main()
{
	int i, j;
	cin >> N >> M >> T;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) puriX = i;
		}
	}

	for (i = 0; i < T; i++) {
		spread();
		purify();
	}

	int ans = 2;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			ans += board[i][j];
		}
	}
	cout << ans;

	return 0;
}
