#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> N;

bool include[50];

void print(int idx, int selected) {
	if (selected == 6) {
		for (int i = 1; i < 50; i++) {
			if (include[i]) cout << i << " ";
		}
		cout << "\n";
		return;
	}
	if (idx >= T) return;
	include[N[idx]] = true;
	print(idx + 1, selected + 1);
	include[N[idx]] = false;
	print(idx + 1, selected);
}

int main()
{
	int i, tmp;
	do {
		cin >> T;
		for (i = 0; i < T; i++) {
			cin >> tmp;
			N.push_back(tmp);
		}

		if(T > 0) print(0, 0);
		N.clear();
		cout << "\n";
	} while (T != 0);

	return 0;
}
