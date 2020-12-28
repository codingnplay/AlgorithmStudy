#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int C[10001];
bool calculated[10001];
int value[10001];
bool visited[10001];
vector<int> edges[10001];
pair<vector<int>, vector<int>> next_index[10001];
vector<int> ans;

void print(int n, bool p){
    visited[n] = true;
    if(p){
        for(int e:next_index[n].first){
            if(!visited[e]){
                ans.push_back(e);
                print(e, false);
            }
        }
        for(int e:next_index[n].second){
            if(!visited[e]){
                print(e, true);
            }
        }
    }
    else{
        for(int e:edges[n]){
            if(!visited[e]){
                print(e, true);
            }
        }
    }
}

int dfs(int n, bool selected){

    visited[n] = true;
    int res = 0;

    if(selected){
        res += C[n];
        for(int v : edges[n]){
            if(!visited[v]){
                res += dfs(v, false);
            }
        }
    }
    else{
        for(int v : edges[n]){
            if(!visited[v]){
                if(!calculated[v]){
                    int r1 = dfs(v, true);
                    int r2 = dfs(v, false);

                    if(r1 > r2) {
                        res += r1;
                        value[v] = r1;
                        next_index[n].first.push_back(v);
                    }
                    else{
                        res += r2;
                        value[v] = r2;
                        next_index[n].second.push_back(v);
                    }
                    calculated[v] = true;
                }
                else{
                    res += value[v];
                }
            }
        }
    }

    visited[n] = false;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i, x, y;
    cin >> N;

    for(i=1; i<=N; i++){
        cin >> C[i];
    }

    for(i=0; i<N-1; i++){
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int maxA = 0;

    edges[0].push_back(1);

    cout << dfs(0, false) << "\n";
    
    print(0, true);

    sort(ans.begin(), ans.end());
    for(int a: ans){
        cout << a << " ";
    }

    cout << "\n";

    return 0;
}
