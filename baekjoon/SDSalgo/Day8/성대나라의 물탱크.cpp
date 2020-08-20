#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Node {
	public :
	int depth;
	int liters = 0;
	int parent;
	bool visited;
};

int N, Q, C;
Node Nodes[200001];
vector<int> edges[200001];

void dfs(int n) {
	Nodes[n].visited = true;

	for (int edge : edges[n]) {
		if (!Nodes[edge].visited) {
			Nodes[edge].depth = Nodes[n].depth + 1;
			Nodes[edge].parent = n;
			dfs(edge);
		}
	}
}

void add(int n) {
	while (n != -1) {
		Nodes[n].liters += Nodes[n].depth;
		n = Nodes[n].parent;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> C;
	int i, x, y;
	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		edges[x].push_back(y);
	}

	Nodes[C].parent = -1;
	Nodes[C].depth = 1;
	dfs(C);

	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> x >> y;
		if (x == 1) {
			add(y);
		}
		else {
			cout << Nodes[y].liters << "\n";
		}
	}

	return 0;
}
