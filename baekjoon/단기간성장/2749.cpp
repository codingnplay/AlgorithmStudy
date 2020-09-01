#include <iostream>
#include <list>
#include <vector>
using namespace std;

long long N;
long long base[2][2] = { {1,1}, {1,0} };
long long expo;
long long ans[2][2] = { {1,1},{1,0} };

void multiply() {
	long long tmp[2][2] = { {0,0},{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += base[i][k] * base[k][j] % 1000000;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			base[i][j] = tmp[i][j];
		}
	}
}

void multans() {
	long long tmp[2][2] = { {0,0},{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += ans[i][k] * base[k][j] % 1000000;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	expo = N - 2;
	while (expo > 0) {
		if (expo % 2 == 0) {
			multiply();
			expo /= 2;
		}
		else {
			multans();
			expo -= 1;
		}
	}

	cout << (ans[0][0]) % 1000000;

	return 0;
}
