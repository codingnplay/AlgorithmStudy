#include <iostream>
#include <algorithm>
using namespace std;

short N; int M;
int W[101];
int C[101];
int LtoR[101];
int D[101][10001];
int ans = 10005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    int i, j;
    for (i = 1; i <= N; i++) {
        cin >> W[i];
    }
    for (i = 1; i <= N; i++) {
        cin >> C[i];
        LtoR[i] = LtoR[i - 1] + C[i];
    }

    D[1][C[1]] = W[1];

    for (i = 1; i <= N; i++) {
        for (j = 0; j <= LtoR[i]; j++) {
            if (j >= C[i]) {
                D[i][j] = max(D[i - 1][j], D[i - 1][j - C[i]] + W[i]);
            }
            else {
                D[i][j] = D[i - 1][j];
            }
            if (D[i][j] >= M && ans > j) ans = j;

        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
