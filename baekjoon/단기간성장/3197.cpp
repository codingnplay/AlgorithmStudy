#include <iostream>
#include <list>
#include <vector>
using namespace std;

int board[1500][1500];
bool visited[1500][1500];
bool swanvisited[1500][1500];
int R, C;
int days = 0;
int tx[4] = { 0,0,1,-1 };
int ty[4] = { 1,-1,0,0 };
list<pair<int, int>> swan;
list<pair<pair<int, int>, int>> nextSwan;
list<pair<int, int>> water;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;

	cin >> R >> C;
	int i, j;

	for (i = 0; i < R; i++) {
		cin >> tmp;
		for (j = 0; j < C; j++) {
			if (tmp[j] == '.') board[i][j] = 0;
			else if (tmp[j] == 'X') board[i][j] = 1;
			else {
				board[i][j] = 2;
				swan.push_back(make_pair(i, j));
				swanvisited[i][j] = true;
			}
		}
	}

	board[swan.front().first][swan.front().second] = 3;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (board[i][j] == 0 || board[i][j] == 2 || board[i][j] == 3) {
				visited[i][j] = true;
				for (int k = 0; k < 4; k++) {
					int mx = i + tx[k];
					int my = j + ty[k];
					if (mx >= 0 && my >= 0 && mx < R && my < C) {
						if (board[mx][my] == 1 && !visited[mx][my]) {
							visited[mx][my] = true;
							water.push_back(make_pair(mx, my));
						}
					}
				}
			}
		}
	}

	bool flag = false;
	while (1) {
		while (!swan.empty()) {
			int x = swan.front().first;
			int y = swan.front().second;
			swan.pop_front();

			for (i = 0; i < 4; i++) {
				int mx = x + tx[i];
				int my = y + ty[i];
				if (mx >= 0 && my >= 0 && mx < R && my < C) {
					if (board[mx][my] == 0 && !swanvisited[mx][my]) {
						swanvisited[mx][my] = true;
						swan.push_back(make_pair(mx, my));
						board[mx][my] = board[x][y];
					}
					else if (board[mx][my] == 1 && !swanvisited[mx][my]) {
						swanvisited[mx][my] = true;
						nextSwan.push_back(make_pair(make_pair(mx, my), board[x][y]));
					}
					else if ((board[mx][my] == 2 || board[mx][my] == 3) && board[mx][my] != board[x][y]) {
						flag = true;
						break;
					}
				}
			}

			if (flag) break;
		}

		if (flag) {
			cout << days;
			break;
		}

		int K = water.size();

		for (int k = 0; k < K; k++) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop_front();
			board[x][y] = 0;

			for (int h = 0; h < 4; h++) {
				int mx = x + tx[h];
				int my = y + ty[h];
				if (mx >= 0 && my >= 0 && mx < R && my < C) {
					if (!visited[mx][my] && board[mx][my] == 1) {
						visited[mx][my] = true;
						water.push_back(make_pair(mx, my));
					}
				}
			}
		}

		while (!nextSwan.empty()) {
			int x = nextSwan.front().first.first;
			int y = nextSwan.front().first.second;
			int type = nextSwan.front().second;
			nextSwan.pop_front();
			if (board[x][y] == 0) {
				swan.push_back(make_pair(x, y));
				board[x][y] = type;
			}
		}
		days++;
	}

	return 0;
}
