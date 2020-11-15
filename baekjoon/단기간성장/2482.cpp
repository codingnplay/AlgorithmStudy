#include <iostream>
#include <string>
using namespace std;

int N, K;
int dp[1001][1001];

int main()
{
    cin >> N >> K;

    int i, j;
    for (i = 1; i <= N; i++) {
        dp[i][1] = i;
    }

    for (j = 2; j <= K; j++) {
        for (i = 3; i <= N; i++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
        }
    }

    if (K != 1) {
        cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % 1000000003;
    }
    else {
        cout << dp[N][K];
    }
    return 0;
}
