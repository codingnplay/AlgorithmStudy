#include <iostream>
#include <list>
using namespace std;

int N;
int A[1000];
int D[1000];
int I[1000];
int ans, ansIdx;
list<int> ansList;

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		D[i] = 1;
		I[i] = -1;
	}

	ans = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
				I[i] = j;
			}
		}
		if (D[i] > ans) {
			ans = D[i];
			ansIdx = i;
		}
	}

	cout << ans << "\n";
	ansList.push_front(A[ansIdx]);

	while (I[ansIdx] != -1) {
		ansIdx = I[ansIdx];
		ansList.push_front(A[ansIdx]);
	}

	for (int ansIndex : ansList) {
		cout << ansIndex << " ";
	}

	return 0;
}
