#include <iostream>
#include <algorithm>
using namespace std;

int N;
int D[501][501];
int A[502];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> A[0] >> A[1];
	int x, y;
	for (int i = 2; i <= N; i++) {
		cin >> x >> y;
		A[i] = y;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i + 1; j++) {
			D[j][j+i-1] = 999999999;
			for (int k = j; k < j+i-1; k++) {
				D[j][j+i-1] = min(D[j][j+i-1], D[j][k] + D[k+1][j+i-1] + A[j-1]*A[k]*A[j+i-1]);
			}
		}
	}

	

	cout << D[1][N];

	return 0;
}
