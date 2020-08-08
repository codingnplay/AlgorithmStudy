#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long min, max;
	bool X[1000001] = { false, };

	cin >> min >> max;

	long i, j, k;
	long res;
	for (i = 2; i <= sqrt(max); i++) {
		if (i >= min && X[i - min]) continue;
		j = min/(i*i);
		res = i * i * j;
		while (res <= max) {
			if (res >= min) {
				X[res - min] = true;
			}
			j++;
			res += i * i;
		}
	}

	int count = 0;
	for (i = 0; i <= max - min; i++) {
		if (!X[i]) count++;
	}

	cout << count;

	return 0;
}
