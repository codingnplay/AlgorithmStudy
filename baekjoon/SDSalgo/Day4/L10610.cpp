#include <iostream>
using namespace std;

string str;
int nCount[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sum = 0;

int main()
{
    int i, j;
    cin >> str;

    for (i = 0; i < str.length(); i++) {
        nCount[str[i] - '0']++;
        sum += (str[i] - '0');
    }

    if (sum == 0 || nCount[0] == 0) {
        cout << "-1\n"; return 0;
    }

    if (sum % 3 == 0) {
        ;
    }//1 4 7 10 
    else if (sum % 3 == 1) {
        cout << "-1\n"; return 0;
    }
    else {
        cout << "-1\n"; return 0;
    }

    for (i = 9; i >= 0; i--) {
        if (nCount[i] > 0) {
            cout << i;
            nCount[i]--;
            i++;
        }
    }
    cout << "\n";
     
    return 0;
}
