#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct node {
    int n;
    int cnt;
};

int X, Y;
list<node> bfsQueue;
bool visited[100001];
int current = 0;
int ans = 100000;
int anscnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y;

    bfsQueue.push_back({ X, 0 });
    visited[X] = true;

    if (X == Y) {
        cout << "0\n1\n"; return 0;
    }

    while (!bfsQueue.empty()) {
        int n = bfsQueue.front().n;
        int c = bfsQueue.front().cnt;
        bfsQueue.pop_front();

        visited[n] = true;

        if (c >= ans) break;

        if (n - 1 >= 0 && !visited[n-1]) {
            if (n - 1 != Y) {
                bfsQueue.push_back({ n - 1, c + 1 });
            }
            else {
                anscnt++;
                ans = c + 1;
            }
        }
        if (n + 1 <= 100000 && !visited[n + 1]) {
            if (n + 1 != Y) {
                bfsQueue.push_back({ n + 1, c + 1 });
            }
            else {
                anscnt++;
                ans = c + 1;
            }
        }
        if (2 * n <= 100000 && !visited[2 * n]) {
            if (2 * n != Y) {
                bfsQueue.push_back({ 2 * n, c + 1 });
            }
            else {
                anscnt++;
                ans = c + 1;
            }
        }
    }

    cout << ans << "\n" << anscnt << "\n";

    return 0;
}
