#include <iostream>
#include <queue>
using namespace std;

int n, m;
int cost[101][101];
int bus[101][101];

int main()
{
    cin >> n >> m;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, x, y, c;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            bus[i][j] = 999999999;
            cost[i][j] = 999999999;
        }
    }
    for (i = 0; i < m; i++) {
        cin >> x >> y >> c;
        if (bus[x][y] > c) bus[x][y] = c;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if(i!=j) cost[i][j] = bus[i][j];
        }
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i != j && j != k && k != i)
                    if (cost[i][j] > cost[i][k] + cost[k][j])
                        cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] == 999999999) {
                cout << "0 ";
            }
            else {
                cout << cost[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
