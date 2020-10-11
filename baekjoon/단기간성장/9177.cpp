#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dp[201][201];
string str1, str2, target;
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, x, y;
	cin >> N;
	for (i = 1; i <= N; i++) {

		cin >> str1 >> str2 >> target;
		
		for (x = 0; x <= str1.length(); x++) {
			for (y = 0; y <= str2.length(); y++) {
				dp[x][y] = 0;
			}
		}

		for (x = 1; x <= str1.length(); x++) {
			if (dp[0][x - 1] == x - 1 && target[x - 1] == str2[x - 1]) dp[0][x] = x;
		}
		for (x = 1; x <= str2.length(); x++) {
			if (dp[x - 1][0] == x - 1 && target[x - 1] == str1[x - 1]) dp[x][0] = x;
		}

		for (x = 1; x <= str1.length(); x++) {
			for (y = 1; y <= str2.length(); y++) {
				if (dp[x - 1][y] == x + y - 1 && target[dp[x - 1][y]] == str1[x - 1]) dp[x][y] = x + y;
				else if (dp[x][y - 1] == x + y - 1 && target[dp[x][y - 1]] == str2[y - 1]) dp[x][y] = x + y;
			}
		}

		if (dp[str1.length()][str2.length()] == target.length()) {
			cout << "Data set " << i << ": yes\n";
		}
		else cout << "Data set " << i << ": no\n";
	}

	return 0;
}
