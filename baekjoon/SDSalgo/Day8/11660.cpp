#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int N, M;
int A[1025][1025];
int D[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	D[1][1] = A[1][1];
	for (i = 2; i <= N; i++) {
		D[1][i] = D[1][i - 1] + A[1][i];
		D[i][1] = D[i - 1][1] + A[i][1];
	}

	for (i = 2; i <= N; i++) {
		for (j = 2; j <= N; j++) {
			D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
		}
	}

	int x1, x2, y1, y2;
	for (i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}
