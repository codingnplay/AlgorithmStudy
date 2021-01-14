#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> T)
    {
        cin >> N;
        vector<int> a(N);
        int i;
        T = T * 10000000;
        for (i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ab = -1;
        int arr[2];
        for (i = 0; i < N - 1; i++)
        {
            int start = i + 1;
            int end = N - 1;
            while (start != end)
            {
                int middle = (start + end) / 2;
                if (a[i] + a[middle] == T)
                {
                    start = middle;
                    break;
                }
                if (a[i] + a[middle] > T)
                {
                    end = middle;
                }
                else
                {
                    start = middle + 1;
                }
            }
            if (a[i] + a[start] == T)
            {
                if (a[start] - a[i] > ab)
                {
                    ab = a[start] - a[i];
                    arr[0] = a[i];
                    arr[1] = a[start];
                }
            }
        }
        if (ab != -1)
        {
            cout << "yes " << arr[0] << " " << arr[1] << "\n";
        }
        else
        {
            cout << "danger\n";
        }
    }
    return 0;
}
