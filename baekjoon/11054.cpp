#include <iostream>
#include <vector>
using namespace std;

int N;
int A[1000];
int D[1000];
int ID[1000];
int I[1000];
int ans;

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		D[i] = 1;
		ID[i] = 1;
		I[i] = 0;
	}

	ans = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (A[j] < A[i] && ID[j] + 1 > ID[i]) {
				ID[i] = ID[j] + 1;
				if (D[i] < ID[i]) {
					D[i] = ID[i];
					I[i] = 1;
				}
			}
			if (I[j] == 1 && A[j] > A[i] && ID[j] + 1 > D[i]) {
				D[i] = ID[j] + 1;
				I[i] = -1;
			}
			else if (I[j] == -1 && A[j] > A[i] && D[j] + 1 > D[i]) {
				D[i] = D[j] + 1;
				I[i] = -1;
			}
			else if (A[j] != A[i] && 2 > D[i]) {
				D[i] = 2;
				if (A[j] < A[i]) I[i] = 1;
				else I[i] = -1;
			}
		}
		if (D[i] > ans) ans = D[i];
	}

	cout << ans;

	return 0;
}
