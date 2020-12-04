#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <functional>
using namespace std;

int V, E, K;
vector<pair<int, int>> Edges[2001];
int d1[2001]; //s에서 시작
int d2[2001]; //g에서 시작
int d3[2001]; //h에서 시작
int T, n, m, t, s, g, h;
vector<int> Des;
list<int> ans;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, x, y, z;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		fill(d1, d1 + n + 1, 99999999);
		fill(d2, d2 + n + 1, 99999999);
		fill(d3, d3 + n + 1, 99999999);
		d1[s] = 0; d2[g] = 0; d3[h] = 0;

		for (j = 0; j < m; j++) {
			cin >> x >> y >> z;
			Edges[x].push_back({ z,y });
			Edges[y].push_back({ z,x });
		}
		for (j = 0; j < t; j++) {
			cin >> x;
			Des.push_back(x);
		}

		pq.push({ 0, s });
		while (!pq.empty()) {
			pair<int, int> now = pq.top();
			pq.pop();

			int w = now.first; int v = now.second;
			if (d1[v] < w)
				continue;

			for (pair<int, int> edge : Edges[v]) {
				if (d1[edge.second] > edge.first + w) {
					d1[edge.second] = edge.first + w;
					pq.push({ d1[edge.second], edge.second });
				}
			}
		}

		pq.push({ 0, g });
		while (!pq.empty()) {
			pair<int, int> now = pq.top();
			pq.pop();

			int w = now.first; int v = now.second;
			if (d2[v] < w)
				continue;

			for (pair<int, int> edge : Edges[v]) {
				if (d2[edge.second] > edge.first + w) {
					d2[edge.second] = edge.first + w;
					pq.push({ d2[edge.second], edge.second });
				}
			}
		}

		pq.push({ 0, h });
		while (!pq.empty()) {
			pair<int, int> now = pq.top();
			pq.pop();

			int w = now.first; int v = now.second;
			if (d3[v] < w)
				continue;

			for (pair<int, int> edge : Edges[v]) {
				if (d3[edge.second] > edge.first + w) {
					d3[edge.second] = edge.first + w;
					pq.push({ d3[edge.second], edge.second });
				}
			}
		}


		for (vector<int>::iterator it = Des.begin(); it != Des.end(); it++) {
			if (d1[*it] == d1[g] + d2[h] + d3[*it] || d1[*it] == d1[h] + d3[g] + d2[*it]) {
				ans.push_back(*it);
			}
		}
		ans.sort();
		for (int a : ans) {
			cout << a << " ";
		}
		cout << "\n";

		for (j = 0; j <= n; j++) Edges[j].clear();
		Des.clear();
		ans.clear();
	}

	return 0;
}
