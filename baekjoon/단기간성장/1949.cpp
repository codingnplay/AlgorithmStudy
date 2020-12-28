#include <iostream>
#include <vector>

using namespace std;

int N;
int C[10001];
int DP[10001][2];
bool visited[10001];

vector<int> edges[10001];

void dfs(int n){
    visited[n] = true;

    DP[n][1] = C[n];

    for(int e : edges[n]){
        if(!visited[e]){
            dfs(e);
            if(DP[e][1] > DP[e][0]){
                DP[n][0] += DP[e][1];
            }
            else{
                DP[n][0] += DP[e][0];
            }
            DP[n][1] += DP[e][0];
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i, x, y;
    for(i=1; i<=N; i++){
        cin >> C[i];
    }

    for(i=0; i<N-1; i++){
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    edges[0].push_back(1);

    dfs(0);
    cout << DP[0][0] << "\n";

    return 0;
}
