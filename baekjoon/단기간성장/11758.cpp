#include <iostream>

using namespace std;

int x[4];
int y[4];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    scanf("%d%d%d%d%d%d", &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);

    int area = ((x[2] - x[1])*(y[3] - y[1])) - ((y[2] - y[1])*(x[3] - x[1]));

    if(area > 0){
        cout << "1\n";
    }
    else if(area < 0){
        cout << "-1\n";
    }
    else cout << "0\n";
}
