#include <iostream>

using namespace std;

int T; int fib0[41]; int fib1[41]; int* testcase;

int main()
{
	cin >> T;
	int i;
	testcase = (int*)malloc(sizeof(int) * T);
	for (i = 0; i < T; i++)
		cin >> testcase[i];
	fib0[0] = 1; fib1[0] = 0; fib1[1] = 0; fib1[1] = 1;
	for (i = 2; i < 41; i++) {
		fib0[i] = fib0[i - 1] + fib0[i - 2]; fib1[i] = fib1[i - 1] + fib1[i - 2];
	}
	for (i = 0; i < T; i++) {
		cout << fib0[testcase[i]] << " " << fib1[testcase[i]] << "\n";
	}
}
