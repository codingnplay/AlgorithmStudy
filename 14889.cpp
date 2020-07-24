#include <iostream>
#include <vector>
#include <list>

using namespace std;
int N;
int board[20][20];
bool include[20];
int ans = 999999999;

void find(int idx, int selected) {

	if (idx == N && selected == N / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j && include[i] && include[j]) {
					sum1 += board[i][j];
				}
				else if (i != j && !include[i] && !include[j]) {
					sum2 += board[i][j];
				}
			}
		}
		int sub = abs(sum1 - sum2);
		if (sub < ans)ans = sub;
	}

	if (idx == N || selected > N / 2) return;

	include[idx] = true;
	find(idx + 1, selected + 1);
	include[idx] = false;
	find(idx + 1, selected);
}

int main()
{
	cin >> N;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	find(0, 0);
	cout << ans;
}
