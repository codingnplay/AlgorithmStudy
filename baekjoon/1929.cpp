#include <iostream>

using namespace std;

int N, M;
bool prime[1000001];

int main()
{
	int i;
	for (i = 2; i <= 500000; i++) {
		int multiplier = 2;
		while (i * multiplier <= 1000000) {
			prime[i * multiplier] = true;
			multiplier++;
		}
	}
	prime[1] = true;

	cin >> N >> M;
	for (i = N; i <= M; i++) {
		if (prime[i] == false) cout << i << "\n";
	}
}
