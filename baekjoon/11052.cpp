#include <iostream>

using namespace std;

int N;
int P[1001];

int main()
{
	cin >> N;
	int i, j;

	for (i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (i = 2; i <= N; i++) {
		for (j = 1; j <= i - 1; j++) {
			if (P[i] < P[j] + P[i - j]) P[i] = P[j] + P[i - j];
		}
	}

	cout << P[N];
	return 0;
}
