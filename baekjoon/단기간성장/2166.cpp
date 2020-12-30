#include <iostream>
#include <cmath>

using namespace std;

int N;
double coords[10001][2];

double area(int x, int y)
{
    return (coords[0][0] * coords[x][1] + coords[x][0] * coords[y][1] + coords[y][0] * coords[0][1] - (coords[0][0] * coords[y][1] + coords[y][0] * coords[x][1] + coords[x][0] * coords[0][1])) * 0.5;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> coords[i][0] >> coords[i][1];
    }

    double ans = 0;

    for (i = 1; i < N - 1; i++)
    {
        ans += area(i, i + 1);
    }

    if (ans < 0)
        ans = -ans;

    printf("%.1lf\n", ans);

    return 0;
}
