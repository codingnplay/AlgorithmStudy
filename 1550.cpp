#include <iostream>
using namespace std;

string N;
long long ans = 0;

int main()
{
	cin >> N;
	int i, j = 1;

	for (i = N.size()-1; i >=0; i--) {
		if (N[i] >= '0' && N[i] <= '9') {
			ans += (N[i] - '0') * j;
		}
		else if (N[i] == 'A') {
			ans += 10 * j;
		}
		else if (N[i] == 'B') {
			ans += 11 * j;
		}
		else if (N[i] == 'C') {
			ans += 12 * j;
		}
		else if (N[i] == 'D') {
			ans += 13 * j;
		}
		else if (N[i] == 'E') {
			ans += 14 * j;
		}
		else if (N[i] == 'F') {
			ans += 15 * j;
		}
		j *= 16;
	}

	cout << ans;

	return 0;
}
