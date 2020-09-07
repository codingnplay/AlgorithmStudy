#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;

struct node {
    int cnt;
    string n;
};

bool visited[1000001];
list<node> bfsQueue;
int N, K;
char buff[16];
int ans = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    sprintf(buff, "%d", N);
    bfsQueue.push_back({ 0,buff });

    int i, j;

    while (!bfsQueue.empty()) {
        int c = bfsQueue.front().cnt;
        string a = bfsQueue.front().n;
        bfsQueue.pop_front();

        if (c == K) {
            if (ans == -1 || ans < atoi(a.c_str())) {
                ans = atoi(a.c_str());
            }
        }

        if (c > K) break;

        visited[atoi(a.c_str())] = false;

        for (i = 0; i < a.length(); i++) {
            for (j = i + 1; j < a.length(); j++) {
                string k = a;
                k[i] = a[j]; k[j] = a[i];
                if (k[0] == '0') continue;
                if (!visited[atoi(k.c_str())]) {
                    visited[atoi(k.c_str())] = true;
                    bfsQueue.push_back({ c + 1, k });
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
