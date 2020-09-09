#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int T, F;
map<string, int> Hash;
int parent[200000];
int friends[200000];
int t, f, a1, a2, k;

int findp(int n) {
    if (parent[n] == n) return n;
    return parent[n] = findp(parent[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (t = 0; t < T; t++) {
        cin >> F;
        k = 0;
        string str1, str2;
        Hash.clear();

        for (f = 0; f < 2 * F; f++) {
            parent[f] = f;
            friends[f] = 1;
        }

        for (f = 0; f < F; f++) {
            cin >> str1 >> str2;

            if (Hash.count(str1) == 0) {
                Hash[str1] = k++;
            } if (Hash.count(str2) == 0) {
                Hash[str2] = k++;
            }

            a1 = findp(Hash[str1]);
            a2 = findp(Hash[str2]);

            if (a1 != a2) {
                friends[parent[a1]] += friends[parent[a2]];
                parent[a2] = parent[a1];
            }
            cout << friends[a1] << "\n";
        }
    }

    return 0;
}
