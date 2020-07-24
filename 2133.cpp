#include <iostream>

using namespace std;

int N;
int ans[31];

int main()
{
	int i, j;
	cin >> N;

	ans[0] = 1; ans[1] = 0; ans[2] = 3; ans[3] = 0;

	for (i = 3; i <= N; i++) {
		ans[i] = 3 * ans[i - 2];
		for (j = i - 4; j >= 0; j -= 2) {
			ans[i] += 2*ans[j];
		}
	}

	cout << ans[N];
}
