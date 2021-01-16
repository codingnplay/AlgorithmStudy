#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int P[500001];
bool include[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, i;
    cin >> N;
    vector<pair<int, int>> A(N);
    vector<pair<int, int>> LIS;

    LIS.push_back({-1, -1});

    for (i = 0; i < N; i++)
    {
        cin >> A[i].first >> A[i].second;
        include[A[i].first] = true;
    }
    sort(A.begin(), A.end());
    for (i = 0; i < N; i++)
    {
        if (A[i].second > LIS.back().first)
        {
            P[A[i].first] = LIS[LIS.size() - 1].second;
            LIS.push_back({A[i].second, A[i].first});
        }
        else
        {
            int start = 0;
            int end = LIS.size() - 1;
            while (start < end)
            {
                int middle = (start + end) / 2;
                if (LIS[middle].first >= A[i].second)
                    end = middle;
                else
                    start = middle + 1;
            }
            LIS[start].first = A[i].second;
            LIS[start].second = A[i].first;
            P[A[i].first] = LIS[start - 1].second;
        }
    }

    int count = 0;

    int p = LIS.back().second;
    while (p != -1)
    {
        include[p] = false;
        p = P[p];
        count++;
    }

    cout << N - count << "\n";
    for (i = 0; i <= 500000; i++)
    {
        if (include[i])
        {
            cout << i << "\n";
        }
    }
    return 0;
}
