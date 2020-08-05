#include <iostream>

using namespace std;

int N, ans = 0;

int main()
{
	cin >> N;
	int i, x, y, z;
	for (i = 1; i <= N; i++) {
		if (i < 100) ans++;
		else {
			x = i / 100;
			y = i % 100 / 10;
			z = i % 10;
			if (x - y == y - z) {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}
