#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int S;
bool visited[2001][2001];

priority_queue<pair<int, pair<int, int> > > pq;

int main()
{
    cin >> S;
    int turn = 0;
    pq.push({0, {1, 0}});
    visited[1][0] = true;

    while (!pq.empty())
    {
        int t = -pq.top().first;
        int n = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (n == S)
        {
            cout << t << "\n";
            break;
        }

        if (n - 1 >= 2 && !visited[n - 1][c])
        {
            pq.push({-t - 1, {n - 1, c}});
            visited[n - 1][c] = true;
        }
        if (!visited[n][n])
        {
            pq.push({-t - 1, {n, n}});
            visited[n][n] = true;
        }
        if (n + c <= 2000 && !visited[n + c][c])
        {
            pq.push({-t - 1, {n + c, c}});
            visited[n + c][c] = true;
        }
    }

    return 0;
}
