#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int h[100001];
int seg[400004];

void init() {
    int start = pow(2, (int)ceil(log2(N))) - 1;

    for (int i = 0; i <= 4*N; i++) {
        seg[i] = -1;
    }

    for (int i = 1; i <= N; i++) {
        int n = start + i;
        while (n > 0) {
            if (seg[n] == -1 || h[seg[n]] > h[i]) {
                seg[n] = i;
            }
            n /= 2;
        }
    }
}

int minIndex(int node, int start, int end, int left, int right) {

    if (start >= left && end <= right) {
        return seg[node];
    }
    if (start > right || end < left) {
        return -1;
    }

    int middle = (start + end) / 2;
    int leftIndex = minIndex(2 * node, start, middle, left, right);
    int rightIndex = minIndex(2 * node + 1, middle + 1, end, left, right);

    if (leftIndex == -1) return rightIndex;
    if (rightIndex == -1) return leftIndex;
    if (h[leftIndex] < h[rightIndex]) return leftIndex;
    return rightIndex;
}

long long maxArea(int left, int right) {
    if (left == right) return h[left];
    int index = minIndex(1, 1, pow(2, (int)ceil(log2(N))), left, right);
    long long area = (long long)h[index] * (right - left + 1);

    if (index - 1 >= left) {
        area = max(area, maxArea(left, index - 1));
    }
    if (index + 1 <= right) {
        area = max(area, maxArea(index + 1, right));
    }
    return area;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;

    while (1) {
        cin >> N;
        if (N == 0) break;

        for (i = 1; i <= N; i++) {
            cin >> h[i];
        }

        init();
        cout << maxArea(1, N) << "\n";
    }
    
    return 0;
}
