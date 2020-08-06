#include <iostream>

using namespace std;

int N;
long C[100001];
long D[100001];
long ans = -999999999;
int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> C[i];
	}
	D[0] = C[0];
	ans = C[0];
	for (i = 1; i < N; i++) {
		if (C[i] + D[i - 1] > C[i]) {
			D[i] = D[i - 1] + C[i];
		}
		else {
			D[i] = C[i];
		}
		if (ans < D[i]) ans = D[i];
	}

	cout << ans;
	return 0;
}
