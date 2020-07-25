#include <iostream>

using namespace std;
int N;
int arr[101];
long dp[101][21];

int main()
{
	cin >> N;
	int i, j;

	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1][arr[1]] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0) {
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][arr[N]];
	return 0;
}
