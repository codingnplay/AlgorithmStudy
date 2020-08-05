#include <iostream>
#include <list>

using namespace std;

int A, B;

int main()
{
	cin >> A >> B;
	int i;
	cout << A / B << ".";

	for (i = 0; i < 20; i++) {
		A = A - B * (A / B);
		A = A * 10;
		cout << A / B;

	}
	return 0;
}
