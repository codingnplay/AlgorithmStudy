#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int N, M, S, E;
vector<pair<int, int>> edges[100001];
bool visited[100001];

bool reach(int weight)
{
    queue<int> bfsQueue;
    for (int i = 0; i <= N; i++)
        visited[i] = false;

    bfsQueue.push(S);
    visited[S] = true;
    while (!bfsQueue.empty())
    {
        int next = bfsQueue.front();
        bfsQueue.pop();

        if (next == E)
            return true;

        for (pair<int, int> edge : edges[next])
        {
            if (!visited[edge.second] && edge.first >= weight)
            {
                bfsQueue.push(edge.second);
                visited[edge.second] = true;
            }
        }
    }
    return false;
}

int solve(int low, int high)
{
    if (low == high)
        return low;

    int middle = (low + high) / 2 + 1;
    if (reach(middle))
    {
        return solve(middle, high);
    }
    else
    {
        return solve(low, middle - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, a, b, c;
    int l = 1000000001, h = 0;
    for (i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
        if (c < l)
            l = c;
        if (c > h)
            h = c;
    }

    cin >> S >> E;

    cout << solve(l, h) << "\n";
    return 0;
}
