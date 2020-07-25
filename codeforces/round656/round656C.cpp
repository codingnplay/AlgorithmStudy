#include <iostream>
#include <vector>

using namespace std;
int T, N;
vector<int> ans;
int arr[200000];
int dp[200000];
int dir[200000];
int same[200000];

int main()
{
	int i, t;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;

		for (i = 0; i < N; i++) {
			dp[i] = 1; dir[i] = 0; same[i] = 1;
		}

		for (i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (i = 1; i < N; i++) {
			if (arr[i] > arr[i - 1]) {
				if (dir[i - 1] == -1) {
					dp[i] = same[i - 1] + 1;
				}
				else {
					dp[i] = dp[i - 1] + 1;
				}
			}
			else if (arr[i] == arr[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				dir[i] = dir[i - 1];
				same[i] = same[i - 1] + 1;
			}
			else {
				dp[i] = dp[i - 1] + 1;
				dir[i] = -1;
			}
		}
		ans.push_back(N-dp[N - 1]);
	}

	for (int i : ans) {
		cout << i << "\n";
	}
	return 0;
}