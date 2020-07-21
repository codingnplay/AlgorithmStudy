#include <iostream>
#include <vector>
using namespace std;

int T;
vector<long> N;
long sum;
long ans = 0;
bool include[20];

void print(int idx, int selected) {
	if (idx == T && selected > 0) {
		long tempsum = 0;
		for (int i = 0; i < T; i++) {
			if (include[i]) {
				tempsum += N[i];
			}
		}
		if (tempsum == sum) ans += 1;
	}
	if (idx >= T) return;
	include[idx] = true;
	print(idx + 1, selected + 1);
	include[idx] = false;
	print(idx + 1, selected);
}

int main()
{
	int i, tmp;
	cin >> T >> sum;
	for (i = 0; i < T; i++) {
		cin >> tmp;
		N.push_back(tmp);
	}

	print(0, 0);
	cout << ans;

	return 0;
}
