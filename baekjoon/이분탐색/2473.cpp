#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
vector<int> A;

int main()
{

    cin >> N;
    int i, j, x;

    for (i = 0; i < N; i++)
    {
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    long long ans = 3000000000;
    int arr[30];
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N - 1; j++)
        {
            long long sum = A[i] + A[j];
            int start = j + 1, end = N - 1;
            while (start != end)
            {
                int middle = (start + end) / 2;
                if (abs(sum + A[middle]) < ans)
                {
                    ans = abs(sum + A[middle]);
                    arr[0] = A[i];
                    arr[1] = A[j];
                    arr[2] = A[middle];
                }
                if (sum + A[middle] > 0)
                {
                    end = middle;
                }
                else
                    start = middle + 1;
            }
            if (abs(sum + A[start]) < ans)
            {
                ans = abs(sum + A[start]);
                arr[0] = A[i];
                arr[1] = A[j];
                arr[2] = A[start];
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
