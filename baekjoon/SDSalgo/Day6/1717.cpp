#include <iostream>
using namespace std;

int N, M;
int finda[1000001];

int findf(int n) {
	if (finda[n] == n) return n;
	else {
		return (finda[n] = findf(finda[n]));
	}
}

void add(int a, int b) {
	int f = findf(a);
	finda[f] = findf(b);
}

void init() {
	for (int i = 0; i <= N; i++) {
		finda[i] = i;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, a, b, w;

	cin >> N >> M;
	init();

	for (i = 0; i < M; i++) {
		cin >> j >> a >> b;
		if (j == 0) {
			add(a, b);
		}
		else {
			if (findf(a) == findf(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
