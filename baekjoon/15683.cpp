#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[8][8];
int version[8][8];
int tmp[8][8];

int ans = 999999999;
vector<pair<int, int>> CCTV;
vector<int> vers;

void solve(int idx) {

	int x, y;

	if (idx == CCTV.size()) {

		int i, j;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		for (i = 0; i < CCTV.size(); i++) {
			x = CCTV[i].first; y = CCTV[i].second;
			if (board[x][y] == 1) {
				if (vers[i] == 1) {
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else if (vers[i] == 2) {
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else if (vers[i] == 3) {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
				else {
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
			}
			else if (board[x][y] == 2) {
				if (vers[i] == 1) {
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
			}
			else if (board[x][y] == 3) {
				if (vers[i] == 1) {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else if (vers[i] == 2) {
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
				else if (vers[i] == 3) {
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else {
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
			}
			else if (board[x][y] == 4) {
				if (vers[i] == 1) {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else if (vers[i] == 2) {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else if (vers[i] == 3) {
					for (j = x - 1; j >= 0; j--) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
				}
				else {
					for (j = y + 1; j < M; j++) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = y - 1; j >= 0; j--) {
						if (board[x][j] == 6) break;
						if (board[x][j] == 0) tmp[x][j] = 9;
					}
					for (j = x + 1; j < N; j++) {
						if (board[j][y] == 6)break;
						if (board[j][y] == 0)tmp[j][y] = 9;
					}
				}
			}
			else if (board[x][y] == 5) {
				for (j = y + 1; j < M; j++) {
					if (board[x][j] == 6) break;
					if (board[x][j] == 0) tmp[x][j] = 9;
				}
				for (j = y - 1; j >= 0; j--) {
					if (board[x][j] == 6) break;
					if (board[x][j] == 0) tmp[x][j] = 9;
				}
				for (j = x - 1; j >= 0; j--) {
					if (board[j][y] == 6)break;
					if (board[j][y] == 0)tmp[j][y] = 9;
				}
				for (j = x + 1; j < N; j++) {
					if (board[j][y] == 6)break;
					if (board[j][y] == 0)tmp[j][y] = 9;
				}
			}
		}

		int count = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (board[i][j] == 0 && tmp[i][j] == 0) count++;
			}
		}
		if (count < ans) ans = count;
		return;
	}

	x = CCTV[idx].first; y = CCTV[idx].second;
	if (board[x][y] == 1) {
		vers[idx] = 1;
		solve(idx + 1);
		vers[idx] = 2;
		solve(idx + 1);
		vers[idx] = 3;
		solve(idx + 1);
		vers[idx] = 4;
		solve(idx + 1);
	}
	else if (board[x][y] == 2) {
		vers[idx] = 1;
		solve(idx + 1);
		vers[idx] = 2;
		solve(idx + 1);
	}
	else if (board[x][y] == 3) {
		vers[idx] = 1;
		solve(idx + 1);
		vers[idx] = 2;
		solve(idx + 1);
		vers[idx] = 3;
		solve(idx + 1);
		vers[idx] = 4;
		solve(idx + 1);
	}
	else if (board[x][y] == 4) {
		vers[idx] = 1;
		solve(idx + 1);
		vers[idx] = 2;
		solve(idx + 1);
		vers[idx] = 3;
		solve(idx + 1);
		vers[idx] = 4;
		solve(idx + 1);
	}
	else {
		solve(idx + 1);
	}
}

int main()
{
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6) {
				CCTV.push_back(make_pair(i, j));
				vers.push_back(0);
			}
		}
	}

	solve(0);
	cout << ans;
	return 0;
}
