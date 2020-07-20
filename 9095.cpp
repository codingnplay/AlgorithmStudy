#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> N;
vector<int> ans;

int bf(int n) {
	int res = 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (n > 1) {
		res += bf(n - 1);
	}
	if (n > 2) {
		res += bf(n - 2);
	}
	if (n > 3) {
		res += bf(n - 3);
	}
	return res;
}

int main()
{
	int i;
	cin >> T;
	for (i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		N.push_back(tmp);
	}

	for (int n : N) {
		int res = bf(n);
		ans.push_back(res);
	}

	for (int a : ans) {
		cout << a << " ";
	}

	return 0;
}
