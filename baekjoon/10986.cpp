#include <iostream>

using namespace std;
typedef long long ll;

int N, M;
ll C[1001], D[1000001];
int main(){
    int i;
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(i=1;i<=N;i++){
        cin >> D[i];
    }
    for(i=1;i<=N;i++){
        D[i] = (D[i-1]+D[i])%M;
        C[D[i]]++;
    }
    ll ans = C[0];
    for(i=0;i<M;i++){
        ans += (C[i] * (C[i]-1))/2;
    }
    cout << ans;
    return 0;
}
