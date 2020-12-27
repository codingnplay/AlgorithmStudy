#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100000001

struct Vertex{
    int d;
    int v;
};

int S, E;
int N, M;
Vertex dist[1001];
vector<Vertex> edges[1001];
priority_queue< pair<int, int> > pq;
vector<int> ans;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i, j, k, x, y, z;

    cin >> N >> M;

    for(i=1;i<=N;i++){
        dist[i].v = -1;
        dist[i].d = INF;
    }

    for(i=0;i<M;i++){
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
    }

    cin >> S >> E;
    dist[S].d = 0;

    pq.push({0, S});

    while(!pq.empty()){
        pair<int, int> f = pq.top(); pq.pop();
        int f_dist = -f.first;
        int current = f.second;
        
        if(f_dist > dist[current].d){
            continue;
        }

        for(Vertex v : edges[current]){
            if(dist[v.v].d > f_dist + v.d){
                dist[v.v].d = f_dist + v.d;
                dist[v.v].v = current;
                pq.push({-dist[v.v].d, v.v});
            }
        }
        
    }

    cout << dist[E].d << "\n";
    int anscount = 1;

    while(dist[E].v != -1){
        ans.push_back(E);
        E = dist[E].v;
        anscount++;
    }

    ans.push_back(E);

    cout << anscount << "\n";

    for(vector<int>::iterator a = ans.end() - 1; a!=ans.begin() - 1; a--){
        cout << *a << " ";
    }
    cout << "\n";

    return 0;
}
