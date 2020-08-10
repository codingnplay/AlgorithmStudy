#include <iostream>
#include <vector>
using namespace std;
//a, n, t, c, i

int N, K;
bool include[26] = { false, };
vector<string> str;
int ans = 0;

void dfs(int idx, int selected) {

	if (selected == K) {
		unsigned int i;
		int count = 0;
		for (string s : str) {
			bool flag = true;
			for (i = 0; i < s.size(); i++) {
				if (!include[s[i] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) count++;
		}
		if (count > ans) ans = count;
		return;
	}
	if (idx >= 26 || selected > K) return;

	if (include[idx]) {
		dfs(idx + 1, selected);
		return;
	}

	include[idx] = true;
	dfs(idx + 1, selected + 1);
	include[idx] = false;
	dfs(idx + 1, selected);
}

int main()
{
	cin >> N >> K;
	int i;

	for (i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}

	if (K >= 5) {
		include['a' - 'a'] = true;
		include['n' - 'a'] = true;
		include['t' - 'a'] = true;
		include['c' - 'a'] = true;
		include['i' - 'a'] = true;
		dfs(1, 5);
	}

	cout << ans;
	return 0;
}
