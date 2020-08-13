#include <iostream>
using namespace std;

int N, K;
bool notPrime[1001] = { false, };

int main()
{
    cin >> N >> K;
    int i, j;
    int count = 0;

    for (i = 2; i <= N; i++) {
        if (notPrime[i]) continue;
        for (j = 1; i * j <= N; j++) {
            if (!notPrime[i*j]) {
                notPrime[i * j] = true;
                count++;
                if (count == K) {
                    cout << i * j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
