#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int* A;
int* B;

bool binary_search(int key, int left, int right) {
	int middle = (left + right) / 2;

	if (A[middle] == key) return true;
	if (A[middle] > key&& middle - 1 >= left) {
		return binary_search(key, left, middle - 1);
	}
	if (A[middle] < key && middle + 1 <= right) {
		return binary_search(key, middle + 1, right);
	}
	return false;
}

int main()
{
	int i, j;
	cin >> N;
	A = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> M;
	B = (int*)malloc(sizeof(int) * M);

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(A, A + N);

	for (i = 0; i < M; i++) {
		if (binary_search(B[i], 0, N - 1)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}