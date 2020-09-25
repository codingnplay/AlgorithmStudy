
#include <iostream>
using namespace std;

int P, G;
int parent[100001];
int ans = 0;

int find(int n) {
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

int main()
{
	cin >> G >> P;
	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}

	int p;
	bool flag = true;

	for (int i = 0; i < P; i++) {
		cin >> p;
		if (find(p) != 0 && p <= G && flag) {
			parent[parent[p]] = find(parent[p] - 1);
			ans++;
		}
		else flag = false;
	}

	cout << ans;
}
