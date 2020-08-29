#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> numbers;

void insert(int n, int left, int right) {
	if (left == right) {
		numbers.insert(numbers.begin() + left, n);
		return;
	}
	if (left > right) {
		return;
	}

	int middle = (left + right) / 2;
	if (middle == 0 && n <= numbers[middle]) {
		numbers.insert(numbers.begin(), n);
	}
	else if (0 < middle && n <= numbers[middle] && n >= numbers[middle-1]) {
		numbers.insert(numbers.begin() + middle, n);
	}
	else if (n < numbers[middle]) {
		insert(n, left, middle - 1);
	}
	else {
		insert(n, middle + 1, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int i, tmp;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		insert(tmp, 0, i);
		cout << numbers[i / 2] << "\n";
	}

	return 0;
}
