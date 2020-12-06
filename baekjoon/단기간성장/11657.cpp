#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <functional>
using namespace std;

int N, M;
vector<pair<pair<int, int>, long long>> edges;
vector<long long> d;

#define INF 999999999

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, a, b;
	long long c;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges.push_back({ { a,b }, c });
	}

	d.assign(N + 1, INF);
	d[1] = 0;

	for (i = 0; i < N - 1; i++) {
		for (pair<pair<int, int>, long long> edge : edges) {
			int s = edge.first.first;
			int e = edge.first.second;

			if (d[s] == INF) {
				continue;
			}

			if (d[s] + edge.second < d[e])
				d[e] = d[s] + edge.second;
		}
	}

	vector<long long> checkagain = d;

	for (i = 0; i < N - 1; i++) {
		for (pair<pair<int, int>, long long> edge : edges) {
			int s = edge.first.first;
			int e = edge.first.second;

			if (d[s] == INF) {
				continue;
			}

			if (d[s] + edge.second < d[e])
				d[e] = d[s] + edge.second;
		}
	}

	/*무한 루프 존재*/
	if (checkagain != d) {
		cout << "-1\n";
		return 0;
	}

	for (i = 2; i <= N; i++) {
		if (d[i] == INF)
			cout << "-1\n";
		else cout << d[i] << "\n";
	}

	return 0;
}
