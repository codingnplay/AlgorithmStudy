#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int A[100001];
pair<int, int> tree[400001];
pair<int, int> z;

pair<int, int> init(int index, int start, int end){
    if(start > N) return z;
    if(start == end){
        tree[index].first = A[start];
        tree[index].second = A[start];
        return tree[index];
    }
    else{
        int middle = (start + end) / 2;
        pair<int, int> res1 = init(2*index, start, middle);
        pair<int, int> res2 = init(2*index+1, middle+1, end);
        res1.first = min(res1.first, res2.first);
        res1.second = max(res1.second, res2.second);
        tree[index] = res1;
        return res1;
    }
}

pair<int, int> getminmax(int index, int start, int end, int left, int right){
    if(start > right || end < left) return z;
    if(left <= start && right >= end) {
        return tree[index];
    }
    int middle = (start+end)/2;
    pair<int, int> res1 = getminmax(2*index, start, middle, left, right);
    pair<int, int> res2 = getminmax(2*index+1, middle+1, end, left, right);
    res1.first = min(res1.first, res2.first);
    res1.second = max(res1.second, res2.second);
    return res1;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    z.first = 1000000001; z.second = 0;

    cin >> N >> M;
    int i, x, y;

    for(i=1;i<=N;i++) cin >> A[i];
    int last = pow(2, ceil(log2(N)));
    init(1, 1, last);
    for(i=0;i<M;i++){
        cin >> x >> y;
        pair<int, int> p = getminmax(1, 1, last, x, y);
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
