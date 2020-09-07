#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x[3];
int mi[3];
int ma[3];
int tmp[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cin >> x[0] >> x[1] >> x[2];
    for (int i = 0; i < 3; i++) {
        mi[i] = x[i];
        ma[i] = x[i];
    }

    for (int i = 1; i < N; i++) {
        cin >> x[0] >> x[1] >> x[2];
        tmp[0] = mi[0]; tmp[1] = mi[1]; tmp[2] = mi[2];
        mi[0] = min(tmp[0] + x[0], tmp[1] + x[0]);
        mi[1] = min(min(tmp[0] + x[1], tmp[1] + x[1]), tmp[2] + x[1]);
        mi[2] = min(tmp[1] + x[2], tmp[2] + x[2]);
        tmp[0] = ma[0]; tmp[1] = ma[1]; tmp[2] = ma[2];
        ma[0] = max(tmp[0] + x[0], tmp[1] + x[0]);
        ma[1] = max(max(tmp[0] + x[1], tmp[1] + x[1]), tmp[2] + x[1]);
        ma[2] = max(tmp[1] + x[2], tmp[2] + x[2]);
    }

    cout << max(max(ma[0], ma[1]), ma[2]) << " " << min(min(mi[0], mi[1]), mi[2]) << "\n";
    return 0;
}
