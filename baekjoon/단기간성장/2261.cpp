#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> points[20002];
int psize[20002];
int N;

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int getD(int l, int r) {
    int m = (l + r) / 2;
    int i, j;
    int d = 2000000000;
    for (i = l; i <= m; i++) {
        for (j = m; j <= r; j++) {
            if (i !=m || j!=m) {
                for (int y1 : points[i]) {
                    for (int y2 : points[j]) {
                        if (dist({ i - 10000,y1 }, { j - 10000,y2 }) < d) {
                            d = dist({ i - 10000,y1 }, { j - 10000,y2 });
                        }
                    }
                }
            }
        }
    }
    return d;
}

int minD(int l, int r) {

    if (psize[r + 1] - psize[l] == 0) {
        return -1;
    }
    if (psize[r + 1] - psize[l] == 1) {
        return r - l;
    }
    if (psize[r + 1] - psize[l] == 2) {
        bool flag = false;
        pair<int, int> x1, x2;
        for (int i = l; i <= r; i++) {
            for (int y : points[i]) {
                if (!flag) {
                    x1.first = i - 10000;
                    x1.second = y;
                    flag = true;
                }
                else {
                    x2.first = i - 10000;
                    x2.second = y;
                }
            }
        }
        return dist(x1, x2);
    }
    if (psize[r + 1] - psize[l] == 3) {
        bool flag = false;
        bool flag2 = false;
        pair<int, int> x1, x2, x3;
        for (int i = l; i <= r; i++) {
            for (int y : points[i]) {
                if (!flag) {
                    x1.first = i - 10000;
                    x1.second = y;
                    flag = true;
                }
                else if (!flag2) {
                    x2.first = i - 10000;
                    x2.second = y;
                    flag2 = true;
                }
                else {
                    x3.first = i - 10000;
                    x3.second = y;
                }
            }
        }
        return min(dist(x1, x3), min(dist(x1, x2), dist(x2, x3)));
    }

    int m = (l + r) / 2;
    int minl = minD(l, m);
    int minr = minD(m, r);
    int d = min(minl, minr);
    if (minl == -1) {
        d = minr;
    }
    else if (minr == -1) {
        d = minl;
    }
    int f = getD(m - d, m + d);
    return min(d, f);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int i, x, y;
    for (i = 0; i < N; i++) {
        cin >> x >> y;
        points[x + 10000].push_back(y);
    }

    psize[0] = 0;
    psize[1] = points[0].size();
    for (i = 2; i <= 20001; i++) {
        psize[i] = psize[i - 1] + points[i - 1].size();
    }

    cout << minD(0, 20000);

    return 0;
}
