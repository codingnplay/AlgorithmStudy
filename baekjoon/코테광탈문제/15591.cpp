#include <iostream>
#include <vector>

using namespace std;

int N, Q;
bool visited[5001];
vector<pair<int, int>> edges[5001];

int dfs(int n, int k){
    visited[n] = true;
    int res = 0;
    for(pair<int, int> edge: edges[n]){
        if(!visited[edge.second]){
            if(k <= edge.first){
                res++;
                res += dfs(edge.second, k);
            }
        }
    }
    visited[n] = false;
    return res;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    int x, y, z, i;
    for(i=0;i<N-1;i++){
        cin >> x >> y >> z;
        edges[x].push_back({z,y});
        edges[y].push_back({z,x});
    }
    for(i=0;i<Q;i++){
        cin >> x >> y;
        cout << dfs(y, x) << "\n";
    }

    return 0;
}
