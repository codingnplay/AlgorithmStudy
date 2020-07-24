#include <iostream>

using namespace std;
int N;
int A[1000000];
int B, C;

int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	unsigned long long ans = N;
	for (i = 0; i < N; i++) {
		if ((A[i] - B) > 0) {
			if (A[i] - B - C <= 0) {
				ans += 1;
			}
			else if ((A[i] - B) % C == 0) {
				ans += (A[i] - B) / C;
			}
			else {
				ans += (A[i] - B) / C + 1;
			}
		}
	}

	cout << ans;

	return 0;
}
