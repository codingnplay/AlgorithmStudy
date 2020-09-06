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
int seq[100001];
bool visited[100001];
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y;

    bfsQueue.push_back({ X, 0 });
    seq[X] = -1;
    visited[X] = true;

    while (!bfsQueue.empty()) {
        int n = bfsQueue.front().n;
        int c = bfsQueue.front().cnt;
        bfsQueue.pop_front();

        if (n == Y) {
            cout << c << "\n";
            while (seq[n] != -1) {
                ans.push_back(n);
                n = seq[n];
            }
            ans.push_back(n);
            break;
        }

        if (n - 1 >= 0 && !visited[n - 1]) {
            bfsQueue.push_back({ n - 1, c + 1 });
            seq[n - 1] = n;
            visited[n - 1] = true;
        }
        if (n + 1 <= 100000 && !visited[n + 1]) {
            bfsQueue.push_back({ n + 1, c + 1 });
            seq[n + 1] = n;
            visited[n + 1] = true;
        }
        if (2 * n <= 100000 && !visited[2 * n]) {
            bfsQueue.push_back({ 2 * n, c + 1 });
            seq[2 * n] = n;
            visited[2 * n] = true;
        }
    }

    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }

    return 0;
}
