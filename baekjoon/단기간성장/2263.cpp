#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int inorder[100001];
int postorder[100000];

void solve(int left, int right, int offset) {
    if (left > right) return;
    cout << postorder[right] << " ";
    if (left == right) return;
    int idx = inorder[postorder[right]] - left - offset;
    solve(left, left + idx - 1, offset);
    solve(left + idx, right - 1, offset + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int i, x;
    for (i = 0; i < N; i++) {
        cin >> x;
        inorder[x] = i;
    }
    for (i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    solve(0, N - 1, 0);


    return 0;
}
