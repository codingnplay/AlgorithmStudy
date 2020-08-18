#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, M;
vector<int> BiggerVertexes[501];
vector<int> SmallerVertexes[501];
bool visited[501];

int dfs1(int v) {
	visited[v] = true;

	int res = 1;
	for (int i : BiggerVertexes[v]) {
		if(!visited[i]) res += dfs1(i);
	}
	return res;
}

int dfs2(int v) {
	visited[v] = true;

	int res = 1;
	for (int i : SmallerVertexes[v]) {
		if (!visited[i]) res += dfs2(i);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int i, x, y;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		BiggerVertexes[x].push_back(y);
		SmallerVertexes[y].push_back(x);
	}

	int count = 0;
	for (i = 1; i <= N; i++) {
		if (N + 1 == dfs1(i) + dfs2(i)) {
			count++;
		}
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}
	}
	cout << count;


	return 0;
}
