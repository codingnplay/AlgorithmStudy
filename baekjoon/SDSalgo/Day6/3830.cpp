#include <iostream>
using namespace std;

int N, M;
int finda[100001];
int weight[100001];

int findf(int n) {
	if (finda[n] == n) return n;
	else {
		int pre = finda[n];
		int p = findf(pre);
		weight[n] += weight[pre];
		finda[n] = p;
		return p;
	}
}

void add(int a, int b, int w) {
	int f = findf(a);
	finda[f] = findf(b);
	weight[f] = w + weight[b] - weight[a];
}

void init() {
	for (int i = 0; i <= N; i++) {
		finda[i] = i;
		weight[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, a, b, w;
	char c;

	do {
		cin >> N >> M;

		init();
		for (i = 0; i < M; i++) {
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				add(a, b, w);
			}
			else {
				cin >> a >> b;
				if (a == b) {
					cout << "0\n";
				}
				else if (findf(a) == findf(b)) {
					cout << weight[a] - weight[b] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
			for (j = 1; j <= N; j++) {
				cout << finda[j] << "\t";
			}
			cout << "\n";
			for (j = 1; j <= N; j++) {
				cout << weight[j] << "\t";
			}
			cout << "\n";
		}
	} while (N != 0 && M != 0);

	return 0;
}
