#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Vertex
{
    int x, y;
};

Vertex vertex[1001];
int N, M;
priority_queue<pair<double, pair<int, int>>> pq;
int p[1001];
double ans = 0;
int selected = 0;

int getP(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = getP(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int i, j, x, y;

    for (i = 1; i <= N; i++)
    {
        cin >> x >> y;
        vertex[i] = {x, y};
        p[i] = i;
    }

    for (i = 0; i < M; i++)
    {
        cin >> x >> y;
        if (getP(x) != getP(y))
        {
            selected += 1;
            p[p[x]] = p[y];
        }
    }

    for (i = 1; i <= N; i++)
    {
        for (j = i + 1; j <= N; j++)
        {
            pq.push({-sqrt(pow((double)vertex[i].x - vertex[j].x, 2) + pow((double)vertex[i].y - vertex[j].y, 2)), {i, j}});
        }
    }

    while (selected < N - 1)
    {
        double d = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();

        if (getP(x) != getP(y))
        {
            p[p[x]] = p[y];
            selected += 1;
            ans += d;
        }
    }

    printf("%.2lf\n", ans);

    return 0;
}
