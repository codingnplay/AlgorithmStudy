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
		D[i] = 1;
	}

	ans = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (A[j] < A[i] && D[j] + 1 > D[i]) {
				D[i] = D[j] + 1;
			}
		}
		if (D[i] > ans) ans = D[i];
	}

	cout << ans;

	return 0;
}
