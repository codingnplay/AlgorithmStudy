#include <iostream>
using namespace std;

long long N, K;
long long A = 1;
long long B = 1;

int getpow(long long base, int exp) {
	if (exp == 0) return 1;
	else if (exp == 1) return base;

	if (exp % 2 == 0) {
		return getpow(base * base % 1000000007, exp / 2);
	}
	else {
		return base * getpow(base, exp - 1) % 1000000007;
	}
}

int main()
{
	cin >> N >> K;

	int i;
	for (i = 1; i <= N; i++) {
		A = A * i % 1000000007;
	}

	for (i = 1; i <= K; i++) {
		B = B * i % 1000000007;
	}

	for (i = 1; i <= N - K; i++) {
		B = B * i % 1000000007;
	}
	
	B = getpow(B, 1000000007 - 2);

	cout << A * B % 1000000007;
	return 0;
}
