#include <iostream>
using namespace std;

long long A, B, C;

int main()
{
	cin >> A >> B >> C;
	long long res = 1;

	while (B > 0) {
		if (B % 2 == 0) {
			A = A * A % C;
			B /= 2;
		}
		else {
			res = res * A % C;
			B -= 1;
		}
	}

	cout << res;

	return 0;
}
