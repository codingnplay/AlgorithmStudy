#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int V, E;
int S;
vector<pair<int, int>> edges[20001];
bool visited[20001];
int minCost[20001];
list<pair<int, int>> nextVertex;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;
	cin >> S;
	int i, x, y, w;
	for (i = 0; i < E; i++) {
		cin >> x >> y >> w;
		edges[x].push_back(make_pair(y, w));
	}

	int n = 1;

	for (i = 1; i <= V; i++) {
		minCost[i] = 999999999;
	}
	minCost[S] = 0;

	nextVertex.push_back({S, 0});
	visited[S] = true;

	while (!nextVertex.empty()) {

		pair<int, int> front = nextVertex.front();
		nextVertex.pop_front();

		for (pair<int,int> vertex : edges[front.first]) {
			if (!visited[vertex.first]) {
				minCost[vertex.first] = min(minCost[vertex.first], vertex.second + front.second);
			}
		}

		for (pair<int, int> vertex : edges[front.first]) {
			if (!visited[vertex.first]) {
				nextVertex.push_back(make_pair(vertex.first, minCost[vertex.first]));
				visited[vertex.first] = true;
			}
		}
	}

	for (i = 1; i <= V; i++) {
		if (minCost[i] == 999999999) {
			cout << "INF\n";
		}
		else {
			cout << minCost[i] << "\n";
		}
	}

	return 0;
}
