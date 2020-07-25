#include <iostream>
using namespace std;

string A, B;
long long ans = 0;

int main()
{
	cin >> A >> B;
	int i, j;

	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < B.size(); j++) {
			ans += (A[i] - '0') * (B[j] - '0');
		}
	}

	cout << ans;

	return 0;
}
