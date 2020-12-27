#include <iostream>
#include <queue>

using namespace std;
int N;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long ans  = 0;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i, x;
    for(i=0;i<N;i++){
        cin >> x;
        pq.push(x);
    }

    while(pq.size() >= 2){
        long long x = pq.top(); pq.pop();
        long long y = pq.top(); pq.pop();

        ans += (x+y);
        pq.push(x+y);
    }

    cout << ans << "\n";

    return 0;
}
