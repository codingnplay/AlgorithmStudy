#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

class Edge {
	public:
		int x;
		int y;
		int weight;

		Edge(int _x, int _y, int _weight) {
			x = _x; y = _y; weight = _weight;
	}
};

int N, M;
list<Edge*> edges;
int parent[1001];

bool compare(Edge* a, Edge* b) {
	return a->weight < b->weight;
}

int findf(int n) {
	if (parent[n] == n) return n;
	return (parent[n] = findf(parent[n]));
}

void add(int x, int y) {
	int x_root = findf(x);
	int y_root = findf(y);
	parent[x_root] = y_root;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int i, a, b, x;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> x;
		Edge* newEdge = new Edge(a, b, x);
		edges.push_back(newEdge);
	}
	
	edges.sort(compare);
	for (i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int n = 0;
	int total = 0;
	while (n < N - 1 && !edges.empty()) {
		Edge* head = edges.front();
		edges.pop_front();

		if (findf(head->x) != findf(head->y)) {	
			add(head->x, head->y);
			total += head->weight;
			n++;
		}
	}

	cout << total;

	return 0;
}
