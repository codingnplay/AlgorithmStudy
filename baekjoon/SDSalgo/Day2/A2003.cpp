#include <iostream>
using namespace std;

int N, M;
int A[10001];

int main()
{
	cin >> N >> M;
	
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	int low = 0, high = 0;
	long sum = A[0];
	int count = 0;
	while (high < N) {
		if (sum == M) {
			count++;
			sum -= A[low++];
		}
		else if (sum > M) {
			sum -= A[low++];
		}
		else {
			sum += A[++high];
		}
	}

	cout << count;

	return 0;
}
