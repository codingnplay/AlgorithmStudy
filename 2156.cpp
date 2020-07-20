#include <iostream>
#include <list>
using namespace std;

int N;
int A[10001];
int D[10001];
int ans = 0;

int main()
{
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> A[i];
	}

	D[0] = 0;
	D[1] = A[1];
	if (N >= 2) {
		D[2] = A[1] + A[2];
	}
	for (i = 3; i <= N; i++) {
		int c1 = D[i - 1];
		int c2 = D[i - 2] + A[i];
		int c3 = D[i - 3] + A[i - 1] + A[i];

		if (c1 >= c2 && c1 >= c3) {
			D[i] = c1;
		}
		else if (c2 >= c1 && c2 >= c3) {
			D[i] = c2;
		}
		else {
			D[i] = c3;
		}
	}
	cout << D[N] << "\n";

	return 0;
}
