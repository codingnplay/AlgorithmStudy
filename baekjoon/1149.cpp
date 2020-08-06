#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int c[1001][3];
int dp[1001][3]; //빨강 초록 파랑
int R, G, B;
int N;

int main()
{
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}
	for (i = 0; i < 3; i++) {
		dp[0][i] = c[0][i];
	}
	for (i = 1; i < N; i++) {
		if (dp[i - 1][1] < dp[i - 1][2]) {
			dp[i][0] = dp[i - 1][1] + c[i][0];
		}
		else {
			dp[i][0] = dp[i - 1][2] + c[i][0];
		}
		if (dp[i - 1][0] < dp[i - 1][2]) {
			dp[i][1] = dp[i - 1][0] + c[i][1];
		}
		else {
			dp[i][1] = dp[i - 1][2] + c[i][1];
		}
		if (dp[i - 1][0] < dp[i - 1][1]) {
			dp[i][2] = dp[i - 1][0] + c[i][2];
		}
		else {
			dp[i][2] = dp[i - 1][1] + c[i][2];
		}
	}

	if (dp[N - 1][0] <= dp[N - 1][1] && dp[N - 1][0] <= dp[N - 1][2]) {
		cout << dp[N - 1][0];
	}
	else if (dp[N - 1][1] <= dp[N - 1][0] && dp[N - 1][1] <= dp[N - 1][2]) {
		cout << dp[N - 1][1];
	}
	else
		cout << dp[N - 1][2];

	return 0;
}
