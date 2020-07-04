#include <iostream>
using namespace std;

int* D;
int* C;
int* x;
int N;

int Method(int index) {
	
	int d1 = -1;
	int d2 = -1;
	int d3 = -1;

	d1 = D[index - 2] + C[index];
	if (index >= 3) {
		d2 = D[index - 3] + D[index - 1] + C[index];
	}
	if (index >= 4) {
		d3 = D[index - 4] + D[index - 2] + D[index - 1] + C[index];
	}

	if (d1 > d2 && d1 > d3) return d1;
	if (d2 > d1 && d2 > d3) return d2;
	if (d3 > d1 && d3 > d2) return d3;
}

int main()
{
	cin >> N;

	cout << N;

	D = (int*)malloc(sizeof(int) * (N+1));
	C = (int*)malloc(sizeof(int) * (N+1));
	x = (int*)malloc(sizeof(int) * (N+1));

	int i;
	for (i = 1; i <= N; i++) {
		cin >> C[i];
	}

	cout << N;

	D[0] = 0; D[1] = C[1]; x[0] = 0; x[1] = 1;

	for (i = 2; i <= N; i++) {
		C[i] = Method(i);
	}

	cout << C[N];
}