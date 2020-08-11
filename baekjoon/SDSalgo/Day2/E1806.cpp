#include <iostream>
using namespace std;

int N, S;
int A[100001];

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int low = 0, high = 0;
	int sum = A[0];
	int ans = 999999;

	while (high < N) {
		if (sum >= S) {
			if (ans > high - low + 1) ans = high - low + 1;

			sum -= A[low++];
		}
		else {
			sum += A[++high];
		}
	}

	if (ans == 999999) {
		cout << "0";
	}
	else {
		cout << ans;
	}
	
	return 0;
}
