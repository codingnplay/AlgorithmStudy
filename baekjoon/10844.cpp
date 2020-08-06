#include <iostream>

using namespace std;

int N;
int dp[100][10];
int main()
{
	cin >> N;

	int i, j;

	for (i = 1; i <= 9; i++) dp[0][i] = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
			}
		}
	}
	j = 0;
	for (i = 0; i <= 9; i++)j = (j + dp[N - 1][i])%1000000000;
	cout << j;
	return 0;
}
