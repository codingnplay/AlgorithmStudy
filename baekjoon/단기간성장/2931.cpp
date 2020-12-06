#include <iostream>
using namespace std;

#define LEFT 1
#define RIGHT 2
#define UP 4
#define DOWN 8
char block_figure[16] = { '.', '-', '-', '-', '|', '3', '2', '?', '|', '4', '1', '?', '|', '?', '?', '+' };
char dir[256] = { RIGHT, LEFT, DOWN, UP, };
char predir[4] = { LEFT, RIGHT, UP, DOWN };

char board[27][27];
int R, C, ansX, ansY, ansDir = 0;
int tx[4] = { 0,0,1,-1 };
int ty[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	int i, j, x, dx, dy;
	string tmp;
	for (i = 1; i <= R; i++) {
		cin >> tmp;
		for (j = 1; j <= C; j++) {
			board[i][j] = tmp[j - 1];
		}
	}

	dir['|'] = UP | DOWN; dir['-'] = LEFT | RIGHT;
	dir['1'] = DOWN | RIGHT; dir['2'] = RIGHT | UP; dir['3'] = LEFT | UP; dir['4'] = LEFT | DOWN;
	dir['+'] = UP | DOWN | LEFT | RIGHT;

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			if (board[i][j] != '.' && board[i][j] != 'M' && board[i][j] != 'Z') {
				for (x = 0; x < 4; x++) {
					dx = i + tx[x]; dy = j + ty[x];
					if (board[dx][dy] == '.' && ((dir[board[i][j]] & dir[x]) == dir[x])) {
						ansX = dx; ansY = dy; ansDir |= predir[x];
					}
				}
			}
		}
	}

	printf("%d %d %c\n", ansX, ansY, block_figure[ansDir]);

	return 0;
}
