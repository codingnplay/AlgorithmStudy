#include <iostream>
#include <cmath>

using namespace std;

bool broken[10];

int check(int n)
{
    int res = 0;
    if (n == 0 && broken[0])
        return 0;
    else if (n == 0)
        return 1;

    while (n > 0)
    {
        if (broken[n % 10])
            return 0;
        n = n / 10;
        res++;
    }
    return res;
}

int main()
{
    int i, N, M, x;
    cin >> N >> M;
    for (i = 0; i < M; i++)
    {
        cin >> x;
        broken[x] = true;
    }

    int ans = abs(N - 100);
    for (i = 0; i <= 1000000; i++)
    {
        x = check(i);
        if (x > 0)
        {
            ans = min(ans, x + abs(N - i));
        }
    }
    cout << ans << "\n";
    return 0;
}
