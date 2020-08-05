#include <iostream>

using namespace std;

string chess1[8];
string chess2[8];
int N, M;
string board[50];
int ans = 999999999;

int main()
{
	int i, j, x, y;
	for (i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			chess1[i] = "WBWBWBWB";
			chess2[i] = "BWBWBWBW";
		}
		else {
			chess1[i] = "BWBWBWBW";
			chess2[i] = "WBWBWBWB";
		}
	}

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (i = 0; i < N - 7; i++) {
		for (j = 0; j < M - 7; j++) {
			int count1 = 0;
			int count2 = 0;
			for (x = 0; x < 8; x++) {
				for (y = 0; y < 8; y++) {
					if (board[i + x][j + y] != chess1[x][y]) count1++;
					if (board[i + x][j + y] != chess2[x][y]) count2++;
				}
			}
			if (count1 < ans) ans = count1;
			if (count2 < ans) ans = count2;
		}
	}

	cout << ans;

	return 0;
}
