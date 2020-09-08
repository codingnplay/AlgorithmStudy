#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> edges[1000001];
bool visited[1000001];
int d[1000001][2];

void dfs(int n) {
    visited[n] = true;
    d[n][1] = 1;

    for (int e : edges[n]) {
        if (!visited[e]) {
           dfs(e);
           d[n][0] += d[e][1];
           if (d[e][0] > d[e][1]) {
               d[n][1] += d[e][1];
           }
           else {
               d[n][1] += d[e][0];
           }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int i, x, y;
    for (i = 0; i < N - 1; i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1);
    if (d[1][0] < d[1][1]) cout << d[1][0];
    else cout << d[1][1];

    return 0;
}
