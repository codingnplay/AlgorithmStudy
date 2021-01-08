#include <iostream>
#include <vector>

using namespace std;

int N;
int b[1001];
int a[1001];
bool visited[1001];

bool brute(int k, int n){
    if(n >= N) return true;
    if(b[n]-k <= N && !visited[b[n] - k] && b[n]-k != k){
        a[n+1] = b[n]-k;
        return brute(b[n]-k, n+1);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    int i;
    for(i=0; i<N-1; i++) cin >> b[i];

    for(i=1; i<b[0]; i++){
        if(!visited[i] && b[0] - i != i && b[0]-i <= N){
            visited[i] = true;
            visited[b[0]-i] = true;
            a[0] = i;
            a[1] = b[0] - i;
            if(brute(b[0] - i, 1)) break;
            visited[i] = false;
            visited[b[0]-i] = false;
        }
    }
    for(i=0; i<N; i++) cout << a[i] << " ";

    return 0;
}
