#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, M;
int lcd[100001][18];
int d[100001];
vector<int> vertexes[100001];
bool visited[100001];

void dfs(int n, int depth) {
	visited[n] = true;
	d[n] = depth;

	for (int vertex : vertexes[n]) {
		if (!visited[vertex]) {
			lcd[vertex][0] = n;
			dfs(vertex, depth + 1);
		}
	}
}

void build_lca() {
	int i, j;
	for (j = 1; j < 18; j++) {
		for (i = 1; i <= N; i++) {
			lcd[i][j] = lcd[lcd[i][j - 1]][j - 1];
		}
	}
}

int find_lca(int x, int y) {
	if (d[x] > d[y]) {
		swap(x, y);
	}

	for (int i = 17; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = lcd[y][i];
		}
	}
    
    if(x==y) return x;

	for (int i = 17; i >= 0; i--) {
		if (lcd[x][i] != lcd[y][i]) {
			x = lcd[x][i];
			y = lcd[y][i];
		}
	}
	return lcd[x][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int i, x, y;
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		vertexes[x].push_back(y);
		vertexes[y].push_back(x);
	}
	cin >> M;

	dfs(1, 0);
	build_lca();

	for (i = 0; i < M; i++) {
		cin >> x >> y;
		cout << find_lca(x, y) << "\n";
	}

	return 0;
}
