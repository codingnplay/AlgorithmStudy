#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int lcd[100001][18][3];
int d[100001];
vector<pair<int, int>> vertexes[100001];
bool visited[100001];

void dfs(int n, int depth) {
	visited[n] = true;
	d[n] = depth;

	for (pair<int,int> vertex : vertexes[n]) {
		if (!visited[vertex.first]) {
			lcd[vertex.first][0][0] = n;
			lcd[vertex.first][0][1] = vertex.second;
			lcd[vertex.first][0][2] = vertex.second;
			dfs(vertex.first, depth + 1);
		}
	}
}

void build_lca() {
	int i, j;
	for (j = 1; j < 18; j++) {
		for (i = 1; i <= N; i++) {
			lcd[i][j][0] = lcd[lcd[i][j - 1][0]][j - 1][0];
			lcd[i][j][1] = min(lcd[i][j - 1][1], lcd[lcd[i][j - 1][0]][j - 1][1]);
			lcd[i][j][2] = max(lcd[i][j - 1][2], lcd[lcd[i][j - 1][0]][j - 1][2]);
		}
	}
}

pair<int, int> find_lca(int x, int y) {
	if (d[x] > d[y]) {
		swap(x, y);
	}

	int rmin = 999999999;
	int rmax = -999999999;

	for (int i = 17; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			rmin = min(rmin, lcd[y][i][1]);
			rmax = max(rmax, lcd[y][i][2]);
			y = lcd[y][i][0];
		}
	}

	if (x == y) return make_pair(rmin, rmax);

	for (int i = 17; i >= 0; i--) {
		if (lcd[x][i][0] != lcd[y][i][0]) {
			rmin = min(rmin, min(lcd[x][i][1], lcd[y][i][1]));
			rmax = max(rmax, max(lcd[x][i][2], lcd[y][i][2]));
			x = lcd[x][i][0];
			y = lcd[y][i][0];
		}
	}

	rmin = min(rmin, min(lcd[x][0][1], lcd[y][0][1]));
	rmax = max(rmax, max(lcd[x][0][2], lcd[y][0][2]));

	return make_pair(rmin, rmax);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int i, x, y, z;
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y >> z;
		vertexes[x].push_back(make_pair(y,z));
		vertexes[y].push_back(make_pair(x,z));
	}
	cin >> M;

	dfs(1, 0);
	build_lca();

	for (i = 0; i < M; i++) {
		cin >> x >> y;
		pair<int, int> answer = find_lca(x, y);
		cout << answer.first << " " << answer.second << "\n";
	}

	return 0;
}
