#include <iostream>
#include <vector>
#include <string>

using namespace std;
int T, N;
string str;
vector<int> ans;

int min(int a, int b) {
	if (a <= b) return a;
	return b;
}

int solve(int left, int right, char currentChar, int currentNum) {
	if (currentNum == 1) {
		if (str[left] == currentChar) return 0;
		else return 1;
	}

	int middle = (left + right) / 2;

	int count1 = 0, count2 = 0;
	int i;
	for (i = left; i <= middle; i++) {
		if (currentChar != str[i]) count1++;
	}
	for (i = middle + 1; i <= right; i++) {
		if (currentChar != str[i])count2++;
	}

	int res1 = solve(middle + 1, right, currentChar + 1, currentNum / 2) + count1;
	int res2 = solve(left, middle, currentChar + 1, currentNum / 2) + count2;

	return min(res1, res2);
}

int main()
{
	cin >> T;
	int i;
	for (i = 0; i < T; i++) {
		cin >> N >> str;
		int a = solve(0, N - 1, 'a', N);
		ans.push_back(a);
	}
	for (i = 0; i < T; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}