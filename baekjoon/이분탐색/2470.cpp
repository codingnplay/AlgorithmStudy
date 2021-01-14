#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int i, x;
    for (i = 0; i < N; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.begin() + N);

    int ans = 2000000000;
    int arr[2];
    for (i = 0; i < N - 1; i++)
    {
        int start = i + 1;
        int end = N - 1;
        while (start != end)
        {
            int middle = (start + end) / 2;
            if (abs(a[i] + a[middle]) < ans)
            {
                ans = abs(a[i] + a[middle]);
                arr[0] = a[i];
                arr[1] = a[middle];
            }
            if (a[i] + a[middle] > 0)
            {
                end = middle;
            }
            else
            {
                start = middle + 1;
            }
        }
        if (abs(a[i] + a[start]) < ans)
        {
            ans = abs(a[i] + a[start]);
            arr[0] = a[i];
            arr[1] = a[start];
        }
    }
    for (i = 0; i < 2; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
