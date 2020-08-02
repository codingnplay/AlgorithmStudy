#include <iostream>

using namespace std;

int N, L;
int board[100][100];

int ans = 0;

void check() {

	int i, j, l;
	for (i = 0; i < N; i++) {
		bool res = true;
		bool ladder[100] = { false, };
		
		for (j = 0; j < N - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				continue;
			}
			if (abs(board[i][j] - board[i][j+1]) >= 2) {
				res = false;
				break;
			}
			if (board[i][j] == board[i][j + 1] + 1) {
				if (j + L >= N) {
					res = false;
					break;
				}
				for (l = j + 1; l <= j + L; l++) {
					if (board[i][j + 1] != board[i][l] || ladder[l]) {
						res = false;
						break;
					}
				}
				if (res) {
					for (l = j + 1; l <= j + L; l++) {
						ladder[l] = true;
					}
				}
			}
			else if (board[i][j] == board[i][j + 1] - 1) {
				if (j + 1 - L < 0) {
					res = false;
					break;
				}
				for (l = j; l >= j + 1 - L; l--) {
					if (board[i][l] != board[i][j] || ladder[l]) {
						res = false;
						break;
					}
				}
				if (res) {
					for (l = j; l >= j + 1 - L; l--) {
						ladder[l] = true;
					}
				}
			}
		}

		if (res) {
			ans += 1;
		}
	}

	for (j = 0; j < N; j++) {
		bool res = true;
		bool ladder[100] = { false, };

		for (i = 0; i < N - 1; i++) {
			if (board[i][j] == board[i + 1][j]) {
				continue;
			}
			if (abs(board[i][j] - board[i + 1][j]) >= 2) {
				res = false;
				break;
			}
			if (board[i][j] == board[i + 1][j] + 1) {
				if (i + L >= N) {
					res = false;
					break;
				}
				for (l = i + 1; l <= i + L; l++) {
					if (board[i + 1][j] != board[l][j] || ladder[l]) {
						res = false;
						break;
					}
				}
				if (res) {
					for (l = i + 1; l <= i + L; l++) {
						ladder[l] = true;
					}
				}
			}
			else if (board[i][j] == board[i + 1][j] - 1) {
				if (i + 1 - L < 0) {
					res = false;
					break;
				}
				for (l = i; l >= i + 1 - L; l--) {
					if (board[l][j] != board[i][j] || ladder[l]) {
						res = false;
						break;
					}
				}
				if (res) {
					for (l = i; l >= i + 1 - L; l--) {
						ladder[l] = true;
					}
				}
			}
		}

		if (res) {
			ans += 1;
		}
	}
};

int main()
{
	int i, j;
	cin >> N >> L;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	check();

	cout << ans;
	return 0;
}
