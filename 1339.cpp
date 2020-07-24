#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
vector<string> words;
vector<pair<int, int>> dicAlpha;
int decAlpha[26];
int ans = 0;

bool comp(pair<int,int> a, pair<int,int> b) {
	if (a.first > b.first) return true;
	else return false;
}

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	for (i = 0; i < 26; i++) {
		dicAlpha.push_back(make_pair(0, i));
	}

	for (i = 0; i < N; i++) {
		int digits = 1;
		for (j = words[i].size() - 1; j >= 0; j--) {
			dicAlpha[words[i][j] - 'A'].first += digits;
			digits *= 10;
		}
	}

	sort(dicAlpha.begin(), dicAlpha.end(), comp);

	int curNum = 9;
	for (i = 0; i < 26; i++) {
		if (dicAlpha[i].first == 0) break;
		ans += dicAlpha[i].first * curNum;
		curNum--;
	}

	cout << ans;
}
