#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N1, N2;
int A[1001];
int B[1001];
vector<int> subA;
vector<int> subB;

int main()
{
    cin >> T;
    int i, j;

    cin >> N1;
    for (i = 0; i < N1; i++) {
        cin >> A[i];
    }
    cin >> N2;
    for (i = 0; i < N2; i++) {
        cin >> B[i];
    }

    for (i = 0; i < N1; i++) {
        for (j = i; j < N1; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            subA.push_back(sum);
        }
    }

    for (i = 0; i < N2; i++) {
        for (j = i; j < N2; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += B[k];
            }
            subB.push_back(sum);
        }
    }

    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end());

    int Alow = 0, Ahigh = 1;
    int Blow = subB.size() - 2, Bhigh = subB.size() - 1;
    long long count = 0;

    while (Alow < subA.size() && Bhigh >= 0) {
        if (Ahigh < subA.size() && subA[Alow] == subA[Ahigh]) {
            Ahigh++;
        }
        else if (Blow >= 0 && subB[Blow] == subB[Bhigh]) {
            Blow--;
        }
        else {
            if (subA[Alow] + subB[Bhigh] == T) {
                count += ((long long)Ahigh - Alow) * (Bhigh - Blow);
                Alow = Ahigh;
                Ahigh = Alow + 1;
            }
            else if (subB[Bhigh] > T - subA[Alow]) {
                Bhigh = Blow;
                Blow = Bhigh - 1;
            }
            else {
                Alow = Ahigh;
                Ahigh = Alow + 1;
            }
        }
    }

    cout << count;

    return 0;
}
