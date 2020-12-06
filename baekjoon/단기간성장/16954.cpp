#include <iostream>
#include <queue>
using namespace std;

char board[8][8];
queue<pair<int, int>> bfsQueue;
int tx[8] = { 0,0,1,1,1,-1,-1,-1 };
int ty[8] = { 1,-1,0,1,-1,0,1,-1 };

void aftermove() {
	int i, j;
	for (i = 7; i > 0; i--) {
		for (j = 0; j < 8; j++) {
			board[i][j] = board[i - 1][j];
		}
	}
	for (i = 0; i < 8; i++) {
		board[0][i] = '.';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j;
	for (i = 0; i < 8; i++) {
		cin >> board[i];
	}

	bfsQueue.push({ 100,100 });
	if (board[7][0] != '#') {
		for (i = 0; i < 8; i++) {
			int dx = 7 + tx[i];
			int dy = 0 + ty[i];

			if (dx >= 0 && dx < 8 && dy >= 0 && dy < 8 && board[dx][dy] == '.') {
				bfsQueue.push({ dx,dy });
			}
		}
		bfsQueue.push({ 7,0 });
	}

	
	while (!bfsQueue.empty()) {
		int x = bfsQueue.front().first;
		int y = bfsQueue.front().second;
		bfsQueue.pop();

		if (x == 0 && y == 7) {
			cout << "1\n";
			bfsQueue.push({ 100,100 });
			break;
		}
		if (x == 100 && y == 100) {
			aftermove();
			if(!bfsQueue.empty()) bfsQueue.push({ 100,100 });
		}
		else if (board[x][y] != '#') {
			for (i = 0; i < 8; i++) {
				int dx = x + tx[i];
				int dy = y + ty[i];

				if (dx >= 0 && dx < 8 && dy >= 0 && dy < 8 && board[dx][dy] == '.') {
					bfsQueue.push({ dx,dy });
				}
			}
			bfsQueue.push({x,y});
		}
	}

	if (bfsQueue.empty()) {
		printf("0\n");
	}

	return 0;
}
