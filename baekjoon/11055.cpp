#include <iostream>
#include <vector>
using namespace std;

int N;
int A[1000];
int D[1000];
int ans;

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		D[i] = A[i];
	}

	ans = D[0];
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (A[j] < A[i] && D[j] + A[i] > D[i]) {
				D[i] = D[j] + A[i];
			}
		}
		if (D[i] > ans) ans = D[i];
	}

	cout << ans;

	return 0;
}
