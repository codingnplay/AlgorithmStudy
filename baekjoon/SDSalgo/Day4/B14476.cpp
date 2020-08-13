#include <iostream>
using namespace std;

int A[1000001];
int LtoR[1000001];
int RtoL[1000001];
int N;
int ans = -1;
int out;

int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    LtoR[1] = A[1];
    RtoL[N] = A[N];
    for (int i = 2; i <= N; i++) {
        LtoR[i] = gcd(LtoR[i - 1], A[i]);
    }
    for (int i = N - 1; i >= 1; i--) {
        RtoL[i] = gcd(RtoL[i + 1], A[i]);
    }

    int getGcd;
    int originalGcd = LtoR[N];
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            getGcd = RtoL[2];
        }
        else if (i == N) {
            getGcd = LtoR[N - 1];
        }
        else {
            getGcd = gcd(LtoR[i - 1], RtoL[i + 1]);
        }

        if (originalGcd % getGcd != 0 && ans < getGcd) {
            ans = getGcd;
            out = A[i];
        }
    }

    cout << ans;

    if (ans != -1) {
        cout << " " << out;
    }
    
    return 0;
}
