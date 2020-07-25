#include <iostream>
#include <vector>
#include <list>

using namespace std;
int T, a, b, c;
int x[3];
vector<string> strAns;
list<int> intAns;

int minIndex(int x, int y, int z) {
	if (x <= y && x <= z) return 0;
	else if (y <= x && y <= z) return 1;
	else return 2;
}

bool solve() {
	int minIdx = minIndex(x[0], x[1], x[2]);
	if (minIdx == 0) {
		a = x[0]; // a > b
		c = x[1]; // c > a > b
		if (x[2] == c) {
			b = a;
			return true;
		}
		else {
			b = x[0]; // b > a;
			c = x[2]; // c > b > a
			if (x[1] == c) {
				a = b;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if (minIdx == 1) {
		a = x[1]; // a > c
		b = x[0]; // b > a > c
		if (x[2] == b) {
			c = a;
			return true;
		}
		else {
			c = x[1]; // c > a
			b = x[2]; // b > c > a
			if (x[0] == b) {
				a = c;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		b = x[2]; // b > c
		a = x[0]; // a > b > c
		if (x[1] == a) {
			c = b;
			return true;
		}
		else {
			c = x[2]; // c > b
			a = x[1]; // a > c > b
			if (x[0] == a) {
				b = c;
				return true;
			}
			else {
				return false;
			}
		}
	}
}

int main()
{
	int i, t;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> x[0] >> x[1] >> x[2];
		if (solve()) {
			strAns.push_back("YES");
			intAns.push_back(a); intAns.push_back(b); intAns.push_back(c);
		}
		else {
			strAns.push_back("NO");
		}
	}

	for (t = 0; t < T; t++) {
		if (strAns[t] == "YES") {
			cout << "YES\n";
			for (i = 0; i < 3; i++) {
				cout << intAns.front() << " ";
				intAns.pop_front();
			}
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}