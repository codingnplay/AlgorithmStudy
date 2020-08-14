#include <iostream>
#include <list>

using namespace std;

int N, M, K;
long long comb[202][202];

int main()
{
	cin >> N >> M >> K;

	int total = N + M - 1;
	int a = N;
	int z = M;
	string ans = "";
	long long count = 0;

	int i, j;

	for (i = 0; i <= 200; i++) {
		comb[i][0] = 1;
		comb[i][i] = 1;
	}

	comb[1][0] = 1;
	comb[1][1] = 1;
	comb[0][0] = 1;
	for (i = 2; i <= 200; i++) {
		for (j = 1; j <= i - 1; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
			if (comb[i][j] > 1000000000) comb[i][j] = 1000000000;
		}
	}

	if (comb[total + 1][a] < K) {
		cout << "-1";
		return 0;
	}

	while (count <= K && total >= 0) {
		if (z == 0) {
			ans += 'a';
			a -= 1;
		}
		else if (a == 0) {
			ans += 'z';
			z -= 1;
		}
		else if (count + comb[total][a - 1] >= K) {
			ans += 'a';
			a -= 1;
		}
		else {
			ans += 'z';
			z -= 1;
			count += comb[total][a - 1];
		}
		total -= 1;
	}

	cout << ans;

	return 0;
}
