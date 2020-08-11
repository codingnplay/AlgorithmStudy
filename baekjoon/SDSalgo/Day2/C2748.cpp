#include <iostream>
using namespace std;

int N;
unsigned long long A[91];

int main()
{
	cin >> N;
	int i;
	A[0] = 0;
	A[1] = 1;
	for (i = 2; i <= N; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}
	cout << A[N];
	return 0;
}
