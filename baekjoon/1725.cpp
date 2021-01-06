#include <iostream>
#include <cmath>

using namespace std;

int N;
int h[100001];
int seg[400004];

int init(int index, int start, int end) {
    if(start > N) return -1;
    if(start == end) return seg[index] = start;
    int middle = (start+end)/2;
    int leftIndex = init(2*index, start, middle);
    int rightIndex = init(2*index+1, middle+1, end);
    if(leftIndex == -1) return seg[index] = rightIndex;
    if(rightIndex == -1) return seg[index] = leftIndex;
    if(h[leftIndex] < h[rightIndex]) return seg[index] = leftIndex;
    else return seg[index] = rightIndex;
}

int minIndex(int index, int start, int end, int left, int right) {
    if (start >= left && end <= right) {
        return seg[index];
    }
    if (start > right || end < left) {
        return -1;
    }
    int middle = (start + end) / 2;
    int leftIndex = minIndex(2 * index, start, middle, left, right);
    int rightIndex = minIndex(2 * index + 1, middle + 1, end, left, right);

    if (leftIndex == -1 && rightIndex == -1) return 0;
    if (leftIndex == -1) return rightIndex;
    if (rightIndex == -1) return leftIndex;
    if (h[leftIndex] < h[rightIndex]) return leftIndex;
    return rightIndex;
}

int maxArea(int left, int right) {
    int index = minIndex(1, 1, pow(2, ceil(log2(N))), left, right);
    int area =  h[index] * (right - left + 1);

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

    int i;

    cin >> N;
    for(i=1; i<=N; i++){
        cin >> h[i];
    }

    int last = pow(2, ceil(log2(N)));
    init(1, 1, last);
    cout << maxArea(1, N);
    
    return 0;
}
