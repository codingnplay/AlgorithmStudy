#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, K;
long long T[4000004] = { 0, };

void build_tree(int n, long long k) {
	while (n != 0) {
		T[n / 2] += k;
		n = n / 2;
	}
}

long long sum(int a, int b, int left, int right, int node) {
	if (left > b || right < a || left > right) {
		return 0;
	}
	if (a <= left && right <= b) {
		return T[node];
	}

	int middle = (left + right) / 2;
	return sum(a, b, left, middle, node * 2) + sum(a, b, middle + 1, right, node * 2 + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> T[(int)pow(2, (ceil(log2(N)))) + i];
		build_tree((int)pow(2, (ceil(log2(N)))) + i, T[(int)pow(2, (ceil(log2(N)))) + i]);
	}

	int a, b;
	long long c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			build_tree((int)pow(2, (ceil(log2(N)))) + b - 1, c - T[(int)pow(2, (ceil(log2(N)))) + b - 1]);
			T[(int)pow(2, (ceil(log2(N)))) + b - 1] = c;
		}
		else {
			cout << sum(b, c, 1, (int)pow(2, (ceil(log2(N)))), 1) << "\n";
		}
	}

	return 0;
}
