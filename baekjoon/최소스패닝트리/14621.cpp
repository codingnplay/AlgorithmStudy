#include <iostream>
#include <queue>

using namespace std;

int N, M;
char type[1001];
int p[1001];
priority_queue<pair<int, pair<int, int>>> pq;

int getp(int n)
{
    if (p[n] == n)
        return n;
    else
        return p[n] = getp(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, x, y, z;
    for (i = 1; i <= N; i++)
    {
        cin >> type[i];
        p[i] = i;
    }

    for (i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        if (type[x] != type[y])
        {
            pq.push({-z, {x, y}});
        }
    }

    int selected = 0;
    int total = 0;

    while (selected < N - 1 && !pq.empty())
    {
        int c = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();

        if (getp(x) != getp(y))
        {
            p[p[x]] = p[y];
            selected += 1;
            total += c;
        }
    }

    if (selected != N - 1)
        cout << "-1\n";
    else
        cout << total << "\n";

    return 0;
}
