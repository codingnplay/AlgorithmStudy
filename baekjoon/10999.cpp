#include <iostream>
#include <cmath>

using namespace std;
int N, M, K;
long long A[1000001];
long long seg[4000004];
long long lazy[4000004];

long long init(int index, int start, int end){
    if(start > N) return 0;
    if(start == end)return seg[index] = A[start];
    int middle = (start+end)/2;
    return seg[index] = init(2*index, start, middle) + init(2*index + 1, middle + 1, end);
}

long long sum(int index, int start, int end, int left, int right){
    if(lazy[index] != 0){
        seg[index] += lazy[index] * (end-start+1); 
        if(start != end){
            lazy[index*2] += lazy[index];
            lazy[index*2+1] += lazy[index];
        }
        lazy[index]=0;
    }

    if(start > right || end < left) return 0;
    if(start >= left && end <= right){
        return seg[index];
    }
    int middle = (start+end)/2;
    return sum(2*index, start, middle, left, right) + sum(2*index+1, middle+1, end, left, right);
}

void update(int index, long long diff, int start, int end, int left, int right){
    if(lazy[index] != 0){
        seg[index] += lazy[index] * (end-start+1); 
        if(start != end){
            lazy[index*2] += lazy[index];
            lazy[index*2+1] += lazy[index];
        }
        lazy[index]=0;
    }
    
    if(start > right || end < left) return;

    if(start >= left && end <= right){
        seg[index] += diff * (end-start+1);
        if(start != end){
            lazy[index*2] += diff; 
            lazy[index*2+1] += diff;
        }
        return;
    }
    int middle = (start+end)/2;
    update(index*2, diff, start, middle, left, right);
    update(index*2 + 1, diff, middle+1, end, left, right);
    if(index <= 2000000)
        seg[index] = seg[index*2] + seg[index*2+1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;

    int i, j;
    long long x, y, z;
    for(i=1;i<=N;i++){
        cin >> A[i];
    }

    int last = pow(2, ceil(log2(N)));
    init(1, 1, last);

    for(j=1;j<=4*N;j++) cout << seg[j] << " " ;
    cout << "\n";

    for(i=0;i<M+K;i++){
        cin >> j;
        if(j==1){
            cin >> x >> y >> z;
            update(1, z, 1, last, x, y);
            for(j=1;j<=4*N;j++) cout << lazy[j] << " " ;
            cout << "\n";
            for(j=1;j<=4*N;j++) cout << seg[j] << " ";
            cout << "\n";
        }
        else if(j==2){
            cin >> x >> y;
            cout << sum(1, 1, last, x, y) << "\n";
            for(j=1;j<=4*N;j++) cout << lazy[j] << " " ;
            cout << "\n";
            for(j=1;j<=4*N;j++) cout << seg[j] << " ";
            cout << "\n";
        }
    }

    return 0;
}
