#include <iostream>
using namespace std;

long long N;
long long ans = 0;

int main()
{
	cin >> N;
	int i;

	for (i = 1; i < N; i++) {
		ans += N * i + i;
	}

	cout << ans;

	return 0;
}
