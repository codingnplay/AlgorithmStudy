#include <iostream>

using namespace std;

int N;
int board[100][100];
int ans1 = 0, ans2 = 0;

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (j = 0; j < N; j++) {
			if (tmp[j] == '.') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		int preNum = 0;
		bool flag = false;
		for (j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				if (preNum == 1) {
					flag = true;
				}
				else {
					preNum = 1;
				}
			}
			else {
				preNum = 0;
				if (flag) {
					ans1 += 1;
					flag = false;
				}
			}
		}
		if (flag) {
			ans1 += 1;
			flag = false;
		}
	}

	for (i = 0; i < N; i++) {
		int preNum = 0;
		bool flag = false;
		for (j = 0; j < N; j++) {
			if (board[j][i] == 1) {
				if (preNum == 1) {
					flag = true;
				}
				else {
					preNum = 1;
				}
			}
			else {
				preNum = 0;
				if (flag) {
					ans2 += 1;
					flag = false;
				}
			}
		}
		if (flag) {
			ans2 += 1;
			flag = false;
		}
	}

	cout << ans1 << " " << ans2;
}
