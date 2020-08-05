#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<int,int>> ans;

void solve(int n, int from, int to, int bottom) {

	if (n == 1) {
		ans.push_back(make_pair(from,to));
		return;
	}
	/*else if (n == 2) {
		ans.push_back(make_pair(from,bottom));
		ans.push_back(make_pair(from,to));
		ans.push_back(make_pair(bottom,to));
		return 3;
	}*/

	solve(n - 1, from, bottom, to);
	ans.push_back(make_pair(from,to));
	solve(n - 1, bottom, to, from);
}

int main()
{
	cin >> N;
	solve(N, 1, 3, 2);
	cout << ans.size() << "\n";
	for (pair<int, int>m : ans) {
		cout << m.first << " " << m.second << "\n";
	}

	return 0;
}
