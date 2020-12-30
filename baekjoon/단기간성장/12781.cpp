#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<double, double>> coords;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j, x, y;

    for (i = 0; i < 4; i++)
    {
        cin >> x >> y;
        coords.push_back({x, y});
    }

    // y - y1 = a(x - x1)
    // y = ax - ax1 + y1
    // ey = ax + b
    // fy = cx + d
    // 지나는 점 구하기
    // ax + b = cx + d
    // (a-c)x = (d-b)
    // x = (d-b)/(a-c)

    double a, b, c, d, e = 1.0, f = 1.0;
    double k, l;

    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (coords[i].first == coords[j].first && coords[i].second == coords[j].second)
            {
                cout << "0\n";
                return 0;
            }
        }
    }

    if (coords[0].second == coords[1].second)
    {
        a = 0;
        b = coords[0].second;
    }
    else if (coords[0].first == coords[1].first)
    {
        e = 0;
        a = 1;
        b = -coords[0].first;
    }
    else
    {
        a = (coords[0].second - coords[1].second) / (coords[0].first - coords[1].first);
        b = -a * coords[0].first + coords[0].second;
    }

    if (coords[2].second == coords[3].second)
    {
        c = 0;
        d = coords[2].second;
    }
    else if (coords[2].first == coords[3].first)
    {
        f = 0;
        c = 1;
        d = -coords[2].first;
    }
    else
    {
        c = (coords[2].second - coords[3].second) / (coords[2].first - coords[3].first);
        d = -c * coords[2].first + coords[2].second;
    }

    if ((e == 0 && f == 0) || a == c)
    {
        cout << "0\n";
        return 0;
    }
    else if (e == 0)
    {
        // 0 = x + b
        // y = cx + d
        k = -b;
        l = -b * c + d;
    }
    else if (f == 0)
    {
        // 0 = x + d
        // y = ax + b
        k = -d;
        l = -d * a + b;
    }
    else
    {
        k = (d - b) / (a - c);
        l = a * k + b;
    }

    for (i = 0; i < 4; i++)
    {
        if (k == coords[i].first && l == coords[i].second)
        {
            cout << "0\n";
            return 0;
        }
    }

    double minx = coords[0].first, miny = coords[0].second, maxx = coords[0].first, maxy = coords[0].second;
    double minx2 = coords[2].first, miny2 = coords[2].second, maxx2 = coords[2].first, maxy2 = coords[2].second;

    for (i = 0; i < 2; i++)
    {
        if (coords[i].first < minx)
            minx = coords[i].first;
        if (coords[i].second < miny)
            miny = coords[i].second;
        if (coords[i].first > maxx)
            maxx = coords[i].first;
        if (coords[i].second > maxy)
            maxy = coords[i].second;
    }
    for (i = 2; i < 4; i++)
    {
        if (coords[i].first < minx2)
            minx2 = coords[i].first;
        if (coords[i].second < miny2)
            miny2 = coords[i].second;
        if (coords[i].first > maxx2)
            maxx2 = coords[i].first;
        if (coords[i].second > maxy2)
            maxy2 = coords[i].second;
    }

    if (k >= minx && k <= maxx && k >= minx2 && k <= maxx2 &&
        l >= miny && l <= maxy && l >= miny2 && l <= maxy2)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
