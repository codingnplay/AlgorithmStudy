#include <iostream>
#include <list>

using namespace std;

int A, B, T;

int main()
{
	cin >> T;
	int t, i, j, k;
	for (t = 0; t < T; t++) {
		cin >> A >> B;
		int dp[30][30] = { 0, };
		for (i = 1; i <= B; i++) {
			dp[1][i] = 1;
		}
		for (i = 2; i <= A; i++) {
			for (j = 1; j <= B; j++) {
				int sum = 0;
				for (k = 0; k < j; k++) {
					sum += dp[i - 1][k];
				}
				dp[i][j] = sum;
			}
		}
		long ans = 0;
		for (k = 0; k <= B; k++) {
			ans += dp[A][k];
		}
		cout << ans << "\n";
	}
	return 0;
}
