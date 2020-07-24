#include <iostream>

using namespace std;

int N, M;
int cards[101];
bool include[101];
int ans = 0;

void find(int idx, int selected) {
	if (idx == N+1 && selected == 3) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (include[i]) {
				sum += cards[i];
				//cout << "1 ";
			}
			//else cout << "0 ";
		}
		//cout << "\n";
		if (sum > ans && M >= sum) ans = sum;
	}
	if (idx == N + 1 || selected > 3) return;
	include[idx] = true;
	find(idx + 1, selected + 1);
	include[idx] = false;
	find(idx + 1, selected);
}

int main()
{
	int i;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		cin >> cards[i];
	}

	find(1, 0);
	cout << ans;
}
