#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, i;
    int A[100001];
    int D1[100001];
    int D2[100001];

    cin >> N;

    for(i=1;i<=N;i++){
        cin >> A[i];
    }

    int ans = -1000000000;

    D1[1] = A[1]; D2[N] = A[N];
    ans = max(A[1], ans);
    ans = max(A[N], ans);

    for(i=2;i<=N;i++){
        ans = max(D1[i] = max(A[i], D1[i-1]+A[i]), ans);
    }
    for(i=N-1;i>=1;i--){
        ans = max(D2[i] = max(A[i], D2[i+1]+A[i]), ans);
    }
    for(i=2;i<=N-1;i++){
        ans = max(ans, D1[i-1] + D2[i+1]);
    }
    cout << ans << "\n";
    return 0;
}
