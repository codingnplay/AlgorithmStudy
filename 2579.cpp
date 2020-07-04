#include <iostream>
using namespace std;

int* D;
int* C;
int N;

int Method(int index) {

	int d1 = -1;
	int d2 = -1;

	d1 = D[index - 2] + C[index];
	d2 = D[index - 3] + C[index - 1] + C[index];

	if (d1 >= d2) {return d1; }
	if (d2 >= d1) {return d2; }
}

int main()
{
	cin >> N;

	D = (int*)malloc(sizeof(int) * (N + 1));
	C = (int*)malloc(sizeof(int) * (N + 1));

	int i;
	for (i = 1; i <= N; i++) {
		cin >> C[i];
	}

	D[0] = 0; D[1] = C[1]; C[0] = 0;

	if (N >= 2) {
		D[2] = C[1] + C[2];
	}
	if (N >= 3) {
		if (C[1] > C[2]) {
			D[3] = C[1] + C[3];
		}
		else {
			D[3] = C[2] + C[3];
		}
	}

	for (i = 4; i <= N; i++) {
		D[i] = Method(i);
	}

	cout << D[N];
}