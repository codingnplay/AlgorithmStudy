#include <iostream>

using namespace std;

int N;
long long ans[91];

int main()
{
	int i, j;
	cin >> N;

	ans[0] = 0; ans[1] = 1; ans[2] = 1; ans[3] = 2;

	for (i = 4; i <= N; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}

	cout << ans[N];
}
