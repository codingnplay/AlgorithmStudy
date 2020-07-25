#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> N;
vector<int> ans;

int main()
{
	int i;
	cin >> T;

	for (i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;

		N.push_back(tmp);
	}

	for (i = 0; i < T; i++) {
		int tmp = N[i];
		int n = N[i];
		int digits = 10;

		while (n >= 10) {
			int last_digit = n % 10;
			if (last_digit >= 5) {
				tmp = tmp + digits - last_digit * (digits / 10);
			}
			else {
				tmp = tmp - last_digit * (digits/10);
			}
			digits *= 10;
			n = tmp / (digits/10);
		}
		ans.push_back(tmp);
	}

	for (int i : ans) {
		cout << i << " ";
	}

}
