#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, i;
    cin >> N;
    vector<int> A(N);
    vector<int> LIS;

    LIS.push_back(-1);

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
        if (LIS.back() < A[i])
        {
            LIS.push_back(A[i]);
        }
        else
        {
            vector<int>::iterator l = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *l = A[i];
        }
    }

    cout << N - LIS.size() + 1 << "\n";
    return 0;
}
