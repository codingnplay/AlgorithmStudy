#include <iostream>

using namespace std;

int CCW(long long x1, long long y_1, long long x2, long long y2, long long x3, long long y3)
{
    long long res = x1 * y2 - x1 * y3 + x2 * y3 - x3 * y2 + x3 * y_1 - x2 * y_1;
    if (res > 0)
    {
        return 1;
    }
    if (res == 0)
    {
        return 0;
    }
    return -1;
}

int main()
{

    int x1, x2, x3, x4, y_1, y2, y3, y4;
    cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if ((CCW(x1, y_1, x2, y2, x3, y3) * (CCW(x1, y_1, x2, y2, x4, y4)) < 0) && (CCW(x3, y3, x4, y4, x1, y_1) * CCW(x3, y3, x4, y4, x2, y2)) < 0)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
