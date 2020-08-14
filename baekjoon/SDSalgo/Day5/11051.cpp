#include <iostream>
#include <list>

using namespace std;

int N, K;
int C[1001][1001];

int main()
{
	cin >> N >> K;

	C[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - 1; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
		}
	}

	cout << C[N][K];

	return 0;
}
