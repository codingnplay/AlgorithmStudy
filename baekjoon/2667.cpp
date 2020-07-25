#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[25][25];
bool visited[25][25];
vector<int> houses;

int dfs(int i, int j) {
	int res = 1;
	visited[i][j] = true;

	if (i - 1 >= 0 && board[i - 1][j] == 1 && !visited[i - 1][j]) res += dfs(i - 1, j);
	if (j - 1 >= 0 && board[i][j - 1] == 1 && !visited[i][j - 1]) res += dfs(i, j - 1);
	if (i + 1 < N && board[i + 1][j] == 1 && !visited[i + 1][j]) res += dfs(i + 1, j);
	if (j + 1 < N && board[i][j + 1] == 1 && !visited[i][j + 1]) res += dfs(i, j + 1);

	return res;
}

int main()
{
	int i, j;
	int count;
	cin >> N;

	for (i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (j = 0; j < N; j++) {
			if (tmp[j] == '1') board[i][j] = 1;
			else board[i][j] = 0;
			visited[i][j] = false;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				count = dfs(i, j);
				houses.push_back(count);
			}
		}
	}

	cout << houses.size() << "\n";
	sort(houses.begin(), houses.end());
	for (int house : houses) {
		cout << house << "\n";
	}
}
