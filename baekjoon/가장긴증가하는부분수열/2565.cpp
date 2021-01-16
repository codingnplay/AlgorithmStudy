#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int main()
{

    cin >> N;
    vector<pair<int, int>> container(N);
    vector<int> D(N);
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> container[i].first >> container[i].second;
        D[i] = 1;
    }
    sort(container.begin(), container.end());
    int ans = 1;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (container[i].second >= container[j].second && D[i] < D[j] + 1)
            {
                D[i] = D[j] + 1;
            }
        }
        ans = max(ans, D[i]);
    }

    cout << N - ans << "\n";

    return 0;
}
