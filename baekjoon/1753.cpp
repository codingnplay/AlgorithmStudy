#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int V, E, K;
vector<pair<int, int>> Edges[20001];
int d[20001];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;
	int i, u, v, w;
	for (i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Edges[u].push_back({ w,v });
	}

	fill(d, d + V + 1, 1999999999);
	d[K] = 0;

	pq.push({ 0, K });

	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();

		int v = now.second;
		int w = now.first;

		if (w > d[v])
			continue;

		for (pair<int, int> Edge : Edges[v]) {
			int k = Edge.second;
			if (d[k] > w + Edge.first) {
				d[k] = w + Edge.first;
				pq.push({ d[k], k });
			}
		}
	}

	for (i = 1; i <= V; i++) {
		if (d[i] == 1999999999)
			cout << "INF\n";
		else cout << d[i] << "\n";
	}

	return 0;
}
