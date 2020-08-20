#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int N, M;
int A[100001];
int LtoR[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int i, j, x, y;
	for (i = 1; i <= N; i++) {
		cin >> A[i];
	}

	LtoR[1] = A[1];

	for (i = 2; i <= N; i++) {
		LtoR[i] = LtoR[i - 1] + A[i];
	}

	for (i = 1; i <= M; i++) {
		cin >> x >> y;
		cout << LtoR[y] - LtoR[x - 1] << "\n";
	}

	return 0;
}
