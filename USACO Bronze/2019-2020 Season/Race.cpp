#include <iostream>
#include <vector>

using namespace std;

int K, N;

//(max+1)(speed+1)
//(max+1) 부터 (speed-1) 까지 더한 것이 dist보다 작고 (max)부터 (speed-1)까지 더한것이 dist보다 크거나 같다

long long sum(long long from, long long to){
    return (to+1)*to/2 - (from-1)*from/2;
}

long long solve(int n){
    long long max = n;
    long long dist = K;
    long long speed = 0;
    long long time = 0;
    while(dist > 0){
        time++;
        if(speed < max){
            speed++;
            dist -= speed;
        }
        else if(sum(max+1, speed+1) < dist){
            speed++;
            dist -= speed;
        }
        else if(sum(max+1, speed-1) < dist && sum(max, speed) > dist){
            speed--;
            dist -= speed;
        }
        else dist -= speed;
    }
    return time;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> K >> N;
    int i, X;
    for(i=0; i<N; i++){
        cin >> X;
        cout << solve(X) << "\n";
    }

    return 0;
}
