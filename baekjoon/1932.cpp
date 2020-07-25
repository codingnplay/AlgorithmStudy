#include <iostream>
#include <algorithm>
using namespace std;

int N;
int** C;
int** D;

int main()
{
	int i, j;
	cin >> N;

	C = (int**)malloc(sizeof(int*) * N);
	D = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		C[i] = (int*)malloc(sizeof(int) * N);
		D[i] = (int*)malloc(sizeof(int) * N);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			cin >> C[i][j];
		}
	}

	D[0][0] = C[0][0];

	for (i = 1; i < N; i++) {
		for (j = 0; j <= i; j++) {
			int tmp1 = -1, tmp2 = -1;
			if (j != 0) {
				tmp1 = D[i - 1][j - 1] + C[i][j];
			}
			if (j != i) {
				tmp2 = D[i - 1][j] + C[i][j];
			}
			if (tmp1 > tmp2) {
				D[i][j] = tmp1;
			}
			else {
				D[i][j] = tmp2;
			}
		}
	}

	sort(&D[N - 1][0], &D[N - 1][N]);

	cout << D[N - 1][N - 1];

	return 0;
}

