#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
bool isWall[1000][1000];
bool visited[1000][1000];
int tx[4] = { 0,0,1,-1 };
int ty[4] = { 1,-1,0,0 };
int d[1000001];
int set[1000][1000];
int s = 0;

int get_d(int n, int m) {
    visited[n][m] = true;
    set[n][m] = s;
    int res = 1;

    for (int i = 0; i < 4; i++) {
        int dx = n + tx[i];
        int dy = m + ty[i];

        if (dx >= 0 && dx < N && dy >= 0 && dy < M && !isWall[dx][dy] && !visited[dx][dy]) {
            res += get_d(dx, dy);
        }
    }

    return res % 10;
}

bool contains(vector<int> vec, int key) {
    for (int v : vec) {
        if (key == v)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string tmp;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> tmp;
        for (j = 0; j < M; j++) {
            if (tmp[j] == '1') isWall[i][j] = true;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (!visited[i][j] && !isWall[i][j]) {
                int _d = get_d(i, j);
                d[s] = _d;
                s++;
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (!isWall[i][j]) {
                cout << '0';
            }
            else {
                vector<int> checkset;
                int res = 1;
                for (int x = 0; x < 4; x++) {
                    int dx = tx[x] + i;
                    int dy = ty[x] + j;
                    if (dx >= 0 && dx < N && dy >= 0 && dy < M && !isWall[dx][dy] && !contains(checkset, set[dx][dy])) {
                        res = (res + d[set[dx][dy]]) % 10;
                        checkset.push_back(set[dx][dy]);
                    }
                }
                cout << res;
            }
        }
        cout << "\n";
    }
    return 0;
}
