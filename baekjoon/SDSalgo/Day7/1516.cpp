#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool visited[501];
vector<int> cond[501];
int minTime[501];

int dfs(int n) {
	if (visited[n]) {
		return minTime[n];
	}

	int rmax = 0;
	visited[n] = true;
	for (int vertex : cond[n]) {
		rmax = max(rmax, dfs(vertex));
	}
	return (minTime[n] = rmax + minTime[n]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int i, tmp;
	for (i = 1; i <= N; i++) {
		cin >> minTime[i];
		cin >> tmp;
		while (tmp != -1) {
			cond[i].push_back(tmp);
			cin >> tmp;
		}
	}

	for (i = 1; i <= N; i++) {
		cout << dfs(i) << "\n";
	}
	
	return 0;
}
