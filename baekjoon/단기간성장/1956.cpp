#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 2000000000

int v, e;
int c[401][401];
int ans = INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    int i, j, k, x, y, z;

    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            if (i != j) {
                c[i][j] = INF;
            }
        }
    }

    for (i = 0; i < e; i++) {
        cin >> x >> y >> z;
        if(c[x][y] > z) c[x][y] = z;
    }

    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            for (k = 1; k <= v; k++) {
                if (c[j][i] != INF && c[i][k] != INF 
                    && c[j][k] > c[j][i] + c[i][k]) {
                    c[j][k] = c[j][i] + c[i][k];
                }
            }
        }
    }

    for (i = 1; i <= v; i++) {
        for (k = 1; k <= v; k++) {
            if (i != k) {
                if (c[i][k] != INF && c[k][i] != INF && ans > c[i][k] + c[k][i]) {
                    ans = c[i][k] + c[k][i];
                }
            }
        }
    }

    if (ans == INF) cout << "-1";
    else cout << ans;

    return 0;
}
