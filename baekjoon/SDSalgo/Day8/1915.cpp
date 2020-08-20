#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int D[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int i, j;
	for (i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (j = 0; j < M; j++){
			D[i][j] = str[j] - '0';
		}
	}

	int ans = 0;

	for (i = 0; i < N; i++) {
		if (D[i][0] > ans) ans = D[i][0];
	}
	for (i = 0; i < M; i++) {
		if (D[0][i] > ans)ans = D[i][0];
	}

	for (i = 1; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (D[i][j] == 1) {
				D[i][j] = min(D[i - 1][j], min(D[i - 1][j - 1], D[i][j - 1])) + 1;
				if (D[i][j] > ans) ans = D[i][j];
			}
		}
	}
	
	cout << ans * ans;

	return 0;
}
