#include <iostream>

using namespace std;
int N;
int ans = 0;

int main()
{
	cin >> N;

	N = 1000 - N;

	while (N > 0) {
		if (N >= 500) {
			N -= 500; ans++;
		}
		else if (N >= 100) {
			N -= 100; ans++;
		}
		else if (N >= 50) {
			N -= 50; ans++;
		}
		else if (N >= 10) {
			N -= 10; ans++;
		}
		else if (N >= 5) {
			N -= 5; ans++;
		}
		else {
			N -= 1; ans++;
		}
	}

	cout << ans;
	return 0;
}
