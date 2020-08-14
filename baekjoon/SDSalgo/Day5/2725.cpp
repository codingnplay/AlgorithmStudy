#include <iostream>
#include <list>

using namespace std;

int C;
int N;

int main()
{
	cin >> C;
	int i, j, c;
	int ans;

	for (c = 0; c < C; c++) {
		cin >> N;
		ans = 0;
		int tmp;

		for (i = 2; i <= N; i++) {
			tmp = 1;
			int count = 0;
			int j = 2;
			int n = i;
			while (n > 1) {
				while (n % j == 0) {
					count++;
					n /= j;
				}
				if (count > 0) {
					tmp *= (pow(j, count) - pow(j, count - 1));
					count = 0;
					j++;
				}
				else {
					j++;
				}
			}
			ans += tmp;
		}

		cout << ans * 2 + 3 << "\n";
	}

	return 0;
}
