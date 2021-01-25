#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;

typedef struct Node
{
    int start, end;

    inline bool operator<(const Node &a) const
    {
        if (a.end < end)
            return true;
        return false;
    }
} Node;

vector<pair<int, int> > classes;
priority_queue<Node> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, i, x, y;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        classes.push_back({x, y});
    }

    sort(classes.begin(), classes.end());

    for (i = 0; i < N; i++)
    {
        if (pq.empty())
        {
            pq.push({classes[i].first, classes[i].second});
            ans++;
        }
        else if (pq.top().end <= classes[i].first)
        {
            Node c = pq.top();
            pq.pop();
            c.end = classes[i].second;
            pq.push(c);
        }
        else
        {
            Node c;
            c.start = classes[i].first;
            c.end = classes[i].second;
            pq.push(c);
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
