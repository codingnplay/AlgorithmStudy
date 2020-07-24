#include <iostream>

using namespace std;

int N;
unsigned long long ans = 0;

int main()
{
	cin >> N;

	long long digits = 10;
	int place = 1;

	for (long long i = 1; i <= N; i++) {
		if (i < digits) {
			ans += place;
		}
		else {
			digits *= 10;
			place++;
			ans += place;
		}
	}

	cout << ans;
}
