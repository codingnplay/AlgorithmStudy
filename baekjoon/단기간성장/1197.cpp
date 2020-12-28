#include <iostream>
#include <queue>

using namespace std;

int V, E;
int ans = 0;
int p[10001];
int selected = 0;
priority_queue<pair<int, pair<int, int>>> pq;

int getP(int x){
    if(p[x] == x) return x;

    return (p[x] = getP(p[x]));
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, x, y, z;
    cin >> V >> E;

    for(i=1; i<=V; i++){
        p[i] = i;
    }
    
    for(i=0; i<E; i++){
        cin >> x >> y >> z;
        pq.push({-z, {x, y}});
    }

    while(selected < V - 1){
        int d = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;

        pq.pop();

        if(getP(x) != getP(y)){
            selected += 1;
            ans += d;
            p[p[y]] = p[x];
        }
    }

    cout << ans << "\n";

    return 0;
}
