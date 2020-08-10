#include <iostream>
#include <list>
using namespace std;

int R, C;
string board[51];
int Sx, Sy, Dx, Dy;
int D[51][51];
int currentD = 1;
bool visited[51][51];
bool flag = true;
list<pair<int, int>> bfsQueue;

void expand_water() {
	int i, j;
	char tmpboard[50][50];

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			tmpboard[i][j] = board[i][j];
			if (board[i][j]!='*' && board[i][j] != 'X' && board[i][j] != 'D') {
				if (i > 0 && board[i - 1][j] == '*') tmpboard[i][j] = '*';
				if (j > 0 && board[i][j - 1] == '*') tmpboard[i][j] = '*';
				if (i < R - 1 && board[i + 1][j] == '*')tmpboard[i][j] = '*';
				if (j < C - 1 && board[i][j + 1] == '*')tmpboard[i][j] = '*';
			}
		}
	}

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			board[i][j] = tmpboard[i][j];
		}
	}

}

void bfs() {

	if (bfsQueue.empty()) return;
	int x = bfsQueue.front().first;
	int y = bfsQueue.front().second;
	bfsQueue.pop_front();


	if (board[x][y] == 'D') return;

	if (currentD != D[x][y]) {
		expand_water();
		currentD = D[x][y];
	}

	int ax[4] = { -1,1,0,0 };
	int ay[4] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		int tx = x + ax[i];
		int ty = y + ay[i];
		if (tx >= 0 && ty >= 0 && tx < R && ty < C) {
			if (!visited[tx][ty] && board[tx][ty] != '*' && board[tx][ty] != 'X') {
				visited[tx][ty] = true;
				bfsQueue.push_back(make_pair(tx, ty));
				D[tx][ty] = D[x][y] + 1;
			}
		}
	}

	bfs();
}

int main()
{
	int i, j;
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		board[i] = tmp;
		for (j = 0; j < C; j++) {
			if (board[i][j] == 'S') {
				Sx = i; Sy = j;
			}
			else if (board[i][j] == 'D') {
				Dx = i; Dy = j;
			}
		}
	}

	D[Sx][Sy] = 1;
	visited[Sx][Sy] = true;
	bfsQueue.push_back(make_pair(Sx, Sy));

	expand_water();
	bfs();

	if (visited[Dx][Dy]) cout << D[Dx][Dy] - 1;
	else cout << "KAKTUS";

	return 0;
}
