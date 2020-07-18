#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int board[101][101];
bool visited[101][101];
int howmany = 0;
vector<int> area;

int dfs(int i, int j) {
	int count = 1;
	visited[i][j] = true;

	if (i > 0 && board[i-1][j] == 0 && !visited[i - 1][j]) {
		count += dfs(i - 1, j);
	}
	if (j > 0 && board[i][j - 1] == 0 && !visited[i][j - 1]) {
		count += dfs(i, j - 1);
	}
	if (i < N - 1 && board[i + 1][j] == 0 && !visited[i + 1][j]) {
		count += dfs(i + 1, j);
	}
	if (j < M - 1 && board[i][j + 1] == 0 && !visited[i][j + 1]) {
		count += dfs(i, j + 1);
	}

	return count;
}


int main()
{
	int i, j, k;
	cin >> M >> N >> K;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			board[i][j] = 0;
			visited[i][j] = false;
		}
	}

	for (k = 0; k < K; k++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (i = lx; i < rx; i++) {
			for (j = ly; j < ry; j++) {
				board[i][j] = 1;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				howmany++;
				area.push_back(dfs(i, j));
			}
		}
	}

	cout << howmany << "\n";
    
    sort(area.begin(), area.end());
	for (i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}

}
