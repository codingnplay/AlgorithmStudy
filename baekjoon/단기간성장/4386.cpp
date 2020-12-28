#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int N;

struct Vertex{
    double x, y;
    int p;
};

Vertex v[101];
priority_queue<pair<double, pair<int, int>>> pq;
int selected = 0;
double ans = 0;

int getP(int x){
    if(v[x].p == x) return x;
    return (v[x].p = getP(v[x].p));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i, j;
    double x, y;

    for(i=0; i<N; i++){
         cin >> x >> y;
         v[i] = {x, y, i};
    }

    for(i=0; i<N;i++){
        for(j=i+1;j<N;j++){
            pq.push({-sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2)), {i, j}});
        }
    }

    while(selected < N - 1){
        double d = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if(getP(a) != getP(b)){
            selected += 1;
            ans += d;
            v[v[a].p].p = v[b].p;
        }
    }

    cout << ans << "\n";

    return 0;
}
