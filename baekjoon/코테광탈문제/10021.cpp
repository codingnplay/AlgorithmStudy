#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, C;
int selected = 0;;
vector<pair<int, int>> v;
priority_queue<pair<int, pair<int, int>>> pq;
int p[2001];
int ans = 0;
int getp(int n){
    if(p[n] == n) return n;
    return p[n] = getp(p[n]);
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    int i, j, x, y;
    for(i=0; i<N; i++){
        p[i] = i;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            pq.push({-pow(v[i].first-v[j].first, 2) - pow(v[i].second - v[j].second, 2), {i,j}});
        }
    }

    while(!pq.empty() && selected < N-1){
        int v = -pq.top().first;
        i = pq.top().second.first; j = pq.top().second.second;
        pq.pop();

        if(v >= C && getp(i)!=getp(j)){
            ans += v;
            p[p[i]] = p[j];
            selected += 1;
        }
    }

    if(selected != N-1) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}
