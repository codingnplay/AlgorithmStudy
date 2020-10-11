#include <iostream>
#include <queue>
using namespace std;

int N;
bool drawn[1005][1005];
pair<int, int> parent[1005][1005];
queue<pair<int, int>> bfsQueue;

pair<int, int> find(pair<int, int> x) {
	if (x == parent[x.first][x.second]) {
		return x;
	}
	return (parent[x.first][x.second] = find(parent[x.first][x.second]));
}

void findParent(int a, int b, int c, int d) {
	int j;
	pair<int, int> p = find({ a,b });
	pair<int, int> t;
	for (j = b; j <= d; j++) {
		t = find(parent[a][j]);
		parent[t.first][t.second] = p;
		t = find(parent[c][j]);
		parent[t.first][t.second] = p;
		drawn[a][j] = true; drawn[c][j] = true;
	}
	for (j = a + 1; j < c; j++) {
		t = find(parent[j][b]);
		parent[t.first][t.second] = p;
		t = find(parent[j][d]);
		parent[t.first][t.second] = p;
		drawn[j][b] = true; drawn[j][d] = true;
	}
}

int tx[4] = { -1,1,0,0 };
int ty[4] = { 0,0,-1,1 };

int main()
{
	int i, j;
	int a, b, c, d;
	for (i = 0; i <= 1000; i++) {
		for (j = 0; j <= 1000; j++) {
			parent[i][j] = { i,j };
		}
	}

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		a += 500; b += 500; c += 500; d += 500;
		findParent(a, b, c, d);
	}

	int ans = 0;

	for (i = 0; i <= 1000; i++) {
		for (j = 0; j <= 1000; j++) {
			if (drawn[i][j]) {
				ans++;
				bfsQueue.push({ i,j });
				drawn[i][j] = false;

				while (!bfsQueue.empty()) {
					pair<int, int> f = bfsQueue.front();
					bfsQueue.pop();
					if (f.first == 500 && f.second == 500) ans--;

					for (int k = 0; k < 4; k++) {
						int dx = f.first + tx[k];
						int dy = f.second + ty[k];
						if (dx >= 0 && dy >= 0 && dx <= 1000 && dy <= 1000 && drawn[dx][dy] && find(parent[f.first][f.second]) == find(parent[dx][dy])) {
							bfsQueue.push({ dx,dy });
							drawn[dx][dy] = false;
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
