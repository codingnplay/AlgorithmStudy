#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int h[100000];
int minH[400000];

void initMinH() {
	int start = pow(2,(int)(ceil(log2(N))));
	int i, now;
	for (i = 0; i < start + N; i++) {
		minH[i] = -1;
	}
	for (i = start; i < start + N; i++) {
		now = i;
		while (now > 0) {
			if (minH[now] == -1 || h[minH[now]] > h[i-start]) {
				minH[now] = i - start;
			}
			now = now / 2;
		}
	}
}

int getMinIndex(int node, int left, int right, int start, int end) {
	if (left <= start && right >= end) {
		return minH[node];
	}
	if (left > end || right < start || left > N) {
		return -1;
	}
	int mid = (start + end) / 2;
	int leftIndex = getMinIndex(2 * node, left, right, start, mid);
	int rightIndex = getMinIndex(2 * node + 1, left, right, mid + 1, end);
	if (leftIndex == -1) return rightIndex;
	if (rightIndex == -1) return leftIndex;
	if (h[leftIndex] < h[rightIndex]) return leftIndex;
	return rightIndex;
}

long maxArea(int left, int right) {
	if (left == right) return h[left];
	int minIndex = getMinIndex(1, left + 1, right + 1, 1, pow(2, (int)(ceil(log2(N)))));
	long area = h[minIndex] * (right - left + 1);
	if (left <= minIndex - 1) {
		area = max(area, maxArea(left, minIndex - 1));
	}
	if (minIndex + 1 <= right) {
		area = max(area, maxArea(minIndex + 1, right));
	}
	return area;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i;

	while (1) {
		cin >> N;
		if (N == 0) break;
		for (i = 0; i < N; i++) {
			cin >> h[i];
		}

		initMinH();
		cout << maxArea(0, N - 1) << "\n";
	}

	return 0;
}
