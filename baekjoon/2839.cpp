#include <iostream>

using namespace std;
int N;
int ans = 9999;

int main()
{
	cin >> N;

	int x, y;
	bool flag = false;
	for (x = 0; x <= N / 5; x++) {
		y = N - 5 * x;
		if (y % 3 == 0) {
			flag = true;
			y = y / 3;
			if (x + y < ans) ans = x + y;
		}
	}

	if (!flag) cout << "-1";
	else cout << ans;

	return 0;
}
