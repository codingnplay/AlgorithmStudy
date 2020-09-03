#include <iostream>
#include <algorithm>
using namespace std;

int C[501];
int F[501];
int D[501][501];
int T, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    int i, j, x, y, tmp;
    for (i = 0; i < T; i++) {
        cin >> N;
        for (j = 0; j < N; j++) {
            cin >> C[j];
        }

        F[0] = 0;
        for (j = 1; j <= N; j++) {
            F[j] = F[j - 1] + C[j-1];
        }
        
        for (x = 0; x < N - 1; x++) {
            D[x][x + 1] = C[x] + C[x + 1];
            D[x][x] = C[x];
        }

        for (x = 2; x <= N - 1; x++) {
            for (y = 0; y < N - x; y++) {
                D[y][y + x] = D[y][y + x - 1] - F[y] + F[y + x + 1];
                for (int k = y + 1; k + 1 < y + x; k++) {
                    D[y][y + x] = min(D[y][y + x], D[y][k] + D[k + 1][y + x] - F[y] + F[y + x + 1]);
                }
                D[y][y + x] = min(D[y][y + x], D[y + 1][y + x] - F[y] + F[y + x + 1]);
            }
        }

        cout << D[0][N-1] << "\n";
    }
    
    return 0;
}
