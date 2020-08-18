#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N, M;
int degree[32001] = { 0, };
bool visited[32001];
vector<int> edges[32001];
list<int> queue;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, a, b, w;

	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> a >> b;
		degree[b]++;
		edges[a].push_back(b);
	}

	j = 0;
	while (j < N) {

		for (i = 1; i <= N; i++) {
			if (!visited[i] && degree[i] == 0) {
				visited[i] = true;
				cout <<  i << " ";
				j++;
				queue.push_back(i);
			}
		}

		while (!queue.empty()) {
			int x = queue.front();
			queue.pop_front();
			for (int edge : edges[x]) {
				degree[edge]--;
			}
		}
	}

	return 0;
}
