#include <iostream>
#include <algorithm>
using namespace std;

int x[4], y[4];
long long s[6];
int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	int i, j;
	for (i = 0; i < T; i++) {
		for (j = 0; j < 4; j++) {
			cin >> x[j] >> y[j];
		}

		for (j = 0; j < 3; j++) {
			s[j] = (x[j + 1] - x[j]) * (x[j + 1] - x[j]) + (y[j + 1] - y[j]) * (y[j + 1] - y[j]);
		}
		s[3] = (x[0] - x[j]) * (x[0] - x[j]) + (y[0] - y[j]) * (y[0] - y[j]);
		s[4] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
		s[5] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);

		sort(s, s + 6);
		if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	return 0;
}
