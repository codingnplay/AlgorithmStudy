#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 99999;
int board[50][50];
vector<pair<int, int>> house, chicken;
bool include[13] = { false, };

void dfs(int idx, int N) {
	if (idx > chicken.size()) return;

	if (N == M) {
		int i, j, totaldis = 0;
		for (i = 0; i < house.size(); i++) {
			int dis = 999;
			for (j = 0; j < chicken.size(); j++) {
				if (include[j] == true) {
					int tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					if (tmp < dis) dis = tmp;
				}
			}
			totaldis += dis;
		}

		if (totaldis < ans) ans = totaldis;

		return;
	}

	//선택함
	include[idx] = true;
	dfs(idx + 1, N + 1);
	//선택안함
	include[idx] = false;
	dfs(idx + 1, N);
}

int main()
{
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (board[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << ans;

	return 0;
}
