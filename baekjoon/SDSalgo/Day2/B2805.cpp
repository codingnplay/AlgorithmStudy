#include <iostream>
using namespace std;

int N, M;
int A[1000001];
int ans = 0;

long getTree(int x) {

	cout << x << "\n";
	long res = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= x) res += (A[i]-x);
	}

	if (res >= M && x > ans) ans = x;
	return res;
}

void solve(int left, int right) {
	if (left > right)return;
	int middle = (left + right) / 2;
	long res = getTree(middle);
	if (res > M) {
		solve(middle + 1, right);
	}
	else if (res == M) {
		return;
	}
	else {
		solve(left, middle - 1);
	}
}

int main()
{
	cin >> N >> M;

	int i, max = 0;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		if (max < A[i])max = A[i];
	}

	solve(0 , max-1);

	cout << ans;
	return 0;
}
