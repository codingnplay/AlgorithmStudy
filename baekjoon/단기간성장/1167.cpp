#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V;
vector<pair<int, int>> edges[100001];
bool visited[100001];
int ans = 0;

int dfs(int n) {
    visited[n] = true;

    int depth1 = 0;
    int depth2 = 0;
    for (pair<int, int> e : edges[n]) {
        if (!visited[e.first]) {
            int tmp = dfs(e.first) + e.second;
            if (depth1 == 0) {
                depth1 = tmp;
            }
            else if (depth2 == 0) {
                depth2 = tmp;
                if (depth2 > depth1) swap(depth1, depth2);
            }
            else if (tmp > depth1) {
                depth2 = depth1;
                depth1 = tmp;
            }
            else if (tmp > depth2) {
                depth2 = tmp;
            }
        }
    }
    ans = max(ans, depth1 + depth2);
    return max(depth1, depth2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V;
    int i, x, y, z;

    for (i = 1; i <= V; i++) {
        cin >> x;
        cin >> y;
        while (y != -1) {
            cin >> z;
            edges[x].push_back({ y,z });
            cin >> y;
        }
    }

    ans = max(ans, dfs(1));

    cout << ans;

    return 0;
}
