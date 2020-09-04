#include <iostream>
#include <list>
using namespace std;

int N, M;
int C[2001];
bool D[2001][2001];
int X, Y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, x;
    cin >> N;
    for (i = 1; i <= N; i++) {
        cin >> C[i];
        D[i][i] = true;
    }

    for (i = 1; i <= N - 1; i++) {
        if (C[i] == C[i + 1]) 
            D[i][i + 1] = true;
    }
    
    for (i = 2; i <= N - 1; i++) {
        for (x = 1; x <= N - i; x++) {
            if (D[x + 1][x + i - 1] && C[x] == C[x + i]) {
                D[x][x + i] = true;
            }
        }
    }

    cin >> M;

    for (i = 0; i < M; i++) {
        cin >> X >> Y;
        cout << D[X][Y] << "\n";
    }
    
    return 0;
}
