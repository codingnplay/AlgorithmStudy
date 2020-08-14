#include <iostream>
#include <list>
#include <string>

using namespace std;

int M, K, N;
int color[51];

int main()
{
	cin >> M;
	int total = 0;

	for (int i = 0; i < M; i++) {
		cin >> color[i];
		total += color[i];
	}
	cin >> K;

	double result = 0;

	for (int i = 0; i < M; i++) {
		double tmp = 1;
		double colorCount = color[i];
		double totalCount = total;
		for (int k = 0; k < K; k++) {
			tmp *= (colorCount-- / totalCount--);
		}
		result += tmp;
	}

	printf("%.10lf", result);

	return 0;
}
