#include <iostream>

using namespace std;

int N;
int ans[1000001];

int main()
{
	cin >> N;

	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;

	for (int i = 4; i <= N; i++) {
		ans[i] = (ans[i - 3] + 2 * ans[i - 2])%15746;
	}

	cout << ans[N];
}
