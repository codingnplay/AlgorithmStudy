#include <iostream>
using namespace std;

int N;
int A[500001];
int B[500001]; //순서
int C[500001];
int tmp[500001];
int tmp2[500001]; //순서 임시저장

void mergeSort(int left, int right) {
	if (left >= right) return;
	int middle = (left + right) / 2;
	mergeSort(left, middle);
	mergeSort(middle + 1, right);

	int i = left, j = middle + 1;
	int k = left;
	while (i <= middle && j <= right) {
		if (A[i] > A[j]) {
			tmp2[k] = B[i];
			tmp[k++] = A[i++];
		}
		else {
			tmp2[k] = B[j];
			tmp[k] = A[j];
			C[B[j]] += (middle - i + 1);
			k++; j++;
		}
	}
	while (i <= middle) {
		tmp2[k] = B[i];
		tmp[k++] = A[i++];
	}
	while (j <= right) {
		tmp2[k] = B[j];
		tmp[k++] = A[j++];
	}

	for (i = left; i <= right; i++) {
		B[i] = tmp2[i];
		A[i] = tmp[i];
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = i;
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << i - C[i] + 1 << "\n";
	}

	return 0;
}
