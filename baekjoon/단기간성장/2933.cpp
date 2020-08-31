#include <iostream>
#include <algorithm>
using namespace std;

int board[100][100];
bool visited[100][100];
int R, C, N;
bool flag = false;
int hitRow;
int over;

void hitCluster() {
	int i;
	if (!flag) {
		for (i = 0; i < C; i++) {
			if (board[R - hitRow][i] > 0) {
				board[R - hitRow][i] = 0;
				return;
			}
		}
	}
	else {
		for (i = C - 1; i >= 0; i--) {
			if (board[R - hitRow][i] > 0) {
				board[R - hitRow][i] = 0;
				return;
			}
		}
	}
}

int tx[4] = { 1,-1,0,0 };
int ty[4] = { 0,0,1,-1 };

int dfs(int i, int j, int n) {

	int res = 0;
	visited[i][j] = true;
	board[i][j] = n;

	for (int x = 0; x < 4; x++) {
		int mx = i + tx[x];
		int my = j + ty[x];
		if (mx >= 0 && my >= 0 && mx < R && my < C && !visited[mx][my] && board[mx][my] > 0) {
			res += dfs(mx, my, n);
		}
	}

	if (i == R - 1) return 1;
	return res;
}

void fallCluster() {
	int i, j;
	int mingap = 1000;

	for (j = 0; j < C; j++) {
		bool present = false;
		bool flag = false;
		int prei = -1;
		int gap;
		for (i = 0; i < R; i++) {
			if (board[i][j] > 0) {
				if (board[i][j] == over) {
					present = true;
					prei = i;
				}
				else if (present){
					flag = true;
					gap = i - prei - 1;
					break;
				}
			}
		}

		if (!flag && present && prei != R - 1) {
			flag = true;
			gap = R - 1 - prei;
		}

		if (flag) {
			mingap = min(gap, mingap);
		}
	}

	for(j = 0; j < C; j++){
		for (i = R - 1; i >= 0; i--) {
			if (board[i][j] == over) {
				board[i][j] = 0;
				board[i + mingap][j] = over;
			}
		}
	}
}

void checkCluster() {
	int i, j;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			visited[i][j] = false;
		}
	}

	over = 0;
	int n = 1;
	for (i = R - 1; i >= 0; i--) {
		for (j = 0; j < C; j++) {
			if (!visited[i][j] && board[i][j] > 0) {
				if (dfs(i, j, n) == 0) {
					over = n;
				}
				n++;
			}
		}
	}

	if (over != 0) {
		fallCluster();
	}
}

int main()
{
	string tmp;

	cin >> R >> C;
	int i, j;

	for (i = 0; i < R; i++) {
		cin >> tmp;
		for (j = 0; j < C; j++) {
			if (tmp[j] == '.') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> hitRow;
		hitCluster();
		checkCluster();

		flag = !flag;
	}

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (board[i][j] == 0) {
				cout << ".";
			}
			else {
				cout << "x";
			}
		}
		cout << "\n";
	}


	return 0;
}
