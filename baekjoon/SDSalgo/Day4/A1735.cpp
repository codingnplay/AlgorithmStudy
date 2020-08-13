#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}

int main()
{
    int A, B, C, D;
    int X, Y;
    cin >> A >> B >> C >> D;
    Y = B * D; X = A * D + B * C;
    int g = gcd(X, Y);
    Y /= g; X /= g;
    cout << X <<" "<< Y;
    return 0;
}
