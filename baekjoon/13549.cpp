#include <iostream>
#include <list>

using namespace std;

int N, K;
bool visited[100001];
list<pair<int, int>> bfsQueue;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int i;
    bfsQueue.push_back({N, 0});
    for (i = N * 2; i <= 100000 && i != 0; i *= 2)
    {
        bfsQueue.push_back({i, 0});
    }

    while (!bfsQueue.empty())
    {
        int n = bfsQueue.front().first;
        int t = bfsQueue.front().second;
        bfsQueue.pop_front();

        if (!visited[n])
        {
            visited[n] = true;
            if (n == K)
            {
                cout << t << "\n";
                return 0;
            }

            for (i = n * 2; i <= 100000 && i != 0; i *= 2)
            {
                if (!visited[i])
                {
                    bfsQueue.push_front({i, t});
                }
            }

            if (n < 100000 && !visited[n + 1])
            {
                bfsQueue.push_back({n + 1, t + 1});
            }

            if (n > 0 && !visited[n - 1])
            {
                bfsQueue.push_back({n - 1, t + 1});
            }
        }
    }

    return 0;
}
