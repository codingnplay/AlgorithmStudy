#include <iostream>
using namespace std;

int N;
long long B;
int matrix[5][5];
int ans[5][5];

void multiply(bool flag) {
	int i, j, k;
	int tmp[5][5];

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			tmp[i][j] = 0;
		}
	}

	if (flag) { //matrix * matrix
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					tmp[i][j] += matrix[i][k] * matrix[k][j] % 1000;
				}
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				matrix[i][j] = tmp[i][j] % 1000;
			}
		}
	}
	else { // ans = ans*matrix
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					tmp[i][j] += ans[i][k] * matrix[k][j] % 1000;
				}
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				ans[i][j] = tmp[i][j] % 1000;
			}
		}
	}
}

int main()
{
	cin >> N >> B;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> matrix[i][j];
			ans[i][j] = matrix[i][j] % 1000;
		}
	}

	B -= 1;

	while (B > 0) {
		if (B % 2 == 0) {
			multiply(true);
			B /= 2;
		}
		else {
			multiply(false);
			B -= 1;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
