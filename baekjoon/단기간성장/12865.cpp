#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101];
int V[101];
int DP[101][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int i, j, k = 0;
	for (i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (i = 1; i <= K; i++) {
		if (i < W[1]) DP[1][i] = 0;
		else DP[1][i] = V[1];
	}

	for (i = 2; i <= N; i++) {
		for (j = 0; j <= K; j++) {
			if (j >= W[i]) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}

	cout << DP[N][K];

	return 0;
}
