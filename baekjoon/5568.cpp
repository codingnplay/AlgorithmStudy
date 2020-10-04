#include <iostream>
using namespace std;

bool visited[100000000];
int selec[4] = {0, 0, 0, 0};
int ans = 0;
int N, K;
int num[10];

void combine(int n, int* arr) {
	if (n == K) {
		int a = 0;
		for (int i = 0; i < K; i++) {
			if (arr[i] < 10) {
				a = a * 10 + arr[i];
			}
			else {
				a = a * 100 + arr[i];
			}
		}
		if (!visited[a]) {
			ans++;
			visited[a] = true;
		}
		return;
	}

	for (int i = 0; i < K; i++) {
		if (arr[i] == -1) {
			arr[i] = selec[n];
			combine(n + 1, arr);
			arr[i] = -1;
		}
	}
}

void solve(int s, int selected) {
	if (s == N+1) return;

	if (selected == K) {
		int arr[4] = { -1,-1,-1,-1 };
		combine(0, arr);
		return;
	}

	selec[selected] = num[s];
	solve(s + 1, selected + 1);
	solve(s + 1, selected);
}

int main()
{
	int i;
	cin >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> num[i];
	}

	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
