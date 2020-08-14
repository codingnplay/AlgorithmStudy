#include <iostream>
#include <list>
#include <string>

using namespace std;

int N, M;
int nCount[10001];
int uniqueCount[10001] = { 0, };

void print(int n, int idx, string str) {
	if (idx == M) {
		cout << str << "\n";
		return;
	}
	for (int i = 0; i < 10001; i++) {
		if (nCount[i] > 0) {
			nCount[i]--;
			print(i, idx + 1, str+" "+to_string(i));
			nCount[i]++;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		nCount[tmp]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (nCount[i] > 0) {
			nCount[i]--;
			print(i, 1, to_string(i));
			nCount[i]++;
		}
	}

	return 0;
}
