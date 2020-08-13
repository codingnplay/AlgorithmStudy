#include <iostream>
using namespace std;

int N, M;
int num1[1000];
int num2[1000];
bool over10to9 = false;
long long gcd = 1;

int getGcd(int a, int b) {
    if (b == 0) return a;
    return getGcd(b, a % b);
}

int main()
{
    int i, j;
    cin >> N;

   for (i = 0; i < N; i++) {
        cin >> num1[i];
    }

    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> num2[i];
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int tmp = getGcd(num1[i], num2[j]);
            if (tmp > 1) {
                gcd *= tmp;
                num1[i] /= tmp;
                num2[j] /= tmp;
                if (gcd >= 1000000000) {
                    gcd %= 1000000000;
                    over10to9 = true;
                }
            }
        }
    }

    if (over10to9) {
        printf("%09d", (int)gcd);
    }
    else
        printf("%d", (int)gcd);
    
    return 0;
}
