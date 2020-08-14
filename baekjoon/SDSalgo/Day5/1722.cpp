#include <iostream>
#include <list>
#include <string>

using namespace std;

int N, T;
long long K;
int num[21];
bool used[21] = { false, };

long long factorial(int n) {
	if (n <= 1) return 1;
	return factorial(n - 1) * n;
}

int main()
{
	cin >> N >> T;

	if (T == 1) {
		cin >> K;
		int remain = N;
		int total = 1;
		long long count = 0;
		while (count < K && total <= N) {
			for (int i = 1; i <= N; i++) {
				if (!used[i]) {
					if (factorial(N - total) + count >= K) {
						used[i] = true;
						cout << i << " ";
						remain--;
						break;
					}
					else {
						count += factorial(N - total);
					}
				}
			}
			total++;
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}

		long long count = 1;
		int idx = 1;
		while (idx <= N) {
			for (int i = 1; i <= N; i++) {
				if (i == num[idx]) {
					used[i] = true;
					break;
				}
				if (!used[i]) {
					count += factorial(N - idx);
				}
			}
			idx++;
		}
		cout << count;
	}

	return 0;
}
