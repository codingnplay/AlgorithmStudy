#include <iostream>

using namespace std;
int N, key;
int board[999][999];

int main()
{
	cin >> N >> key;

	int i, j;
	board[N / 2][N / 2] = 1;
	int x, y;
	int num = 2;

	int fill = 2;
	i = N / 2 - 1; j = N / 2;

	while (num <= N * N) {
		for (int idx = 0; idx < fill; idx++) {
			board[i][j++] = num++;
		}
		j--; i++;
		for (int idx = 0; idx < fill; idx++) {
			board[i++][j] = num++;
		}
		i--;  j--;
		for (int idx = 0; idx < fill; idx++) {
			board[i][j--] = num++;
		}
		j++; i--;
		for (int idx = 0; idx < fill; idx++) {
			board[i--][j] = num++;
		}
		fill += 2;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (board[i][j] == key) {
				x = i; y = j;
			}
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << x + 1 << " " << y + 1;

	return 0;
}
