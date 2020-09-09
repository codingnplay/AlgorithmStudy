#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;
int connected[201][201];
int parent[201];

int findp(int n) {
    if (parent[n] == n) return n;
    parent[n] = parent[parent[n]];
    return findp(parent[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            cin >> connected[i][j];
        }
    }

    for (i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (i = 1; i <= N; i++) {
        for (j = i + 1; j <= N; j++) {
            if (connected[i][j] == 1 && findp(i) != findp(j)) {
                parent[parent[j]] = parent[i];
            }
        }
    }

    int city;
    cin >> city;
    j = findp(city);

    for (i = 1; i < M; i++) {
        cin >> city;
        if (findp(city) != j) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
