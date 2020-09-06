#include <iostream>
using namespace std;

string str1, str2;
pair<int, string> dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;

    int i, j;
    for (i = 0; i <= str1.length(); i++) {
        for (j = 0; j <= str2.length(); j++) {
            dp[i][j].first = 0;
            dp[i][j].second = "";
        }
    }

    for (i = 1; i <= str1.length(); i++) {
        for (j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1] && 1 + dp[i - 1][j - 1].first > dp[i][j - 1].first && 1 + dp[i - 1][j - 1].first > dp[i - 1][j].first) {
                dp[i][j].first = 1 + dp[i - 1][j - 1].first;
                dp[i][j].second = dp[i - 1][j - 1].second + str1[i - 1];
            }
            else if (dp[i - 1][j].first > dp[i][j - 1].first) {
                dp[i][j].first = dp[i - 1][j].first;
                dp[i][j].second = dp[i - 1][j].second;
            }
            else {
                dp[i][j].first = dp[i][j - 1].first;
                dp[i][j].second = dp[i][j - 1].second;
            }
        }
    }

    cout << dp[str1.length()][str2.length()].first << "\n" << dp[str1.length()][str2.length()].second << "\n";
    
    return 0;
}
