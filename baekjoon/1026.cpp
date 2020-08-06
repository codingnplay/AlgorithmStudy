#include <iostream>

using namespace std;

int N;
int A[101];
int B[101];
int ans = 0;

int main()
{
	cin >> N;
	int i, j, x;

	for (i = 0; i < N; i++) {
		cin >> x;
		A[x]++;
	}

	for (i = 0; i < N; i++) {
		cin >> x;
		B[x]++;
	}

	i = 0; j = 100;
	while (i <= 100 && j >= 0) {
		if (A[i] > 0 && B[j] > 0) {
			ans += i * j;
			A[i]--; B[j]--;
		}
		if (A[i] == 0) {
			i++;
		}
		if (B[j] == 0) {
			j--;
		}
	}

	cout << ans;
	return 0;
}
