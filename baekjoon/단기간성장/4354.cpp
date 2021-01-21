#include <iostream>
#include <string>

using namespace std;

int p[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (true)
    {
        cin >> s;
        if (s == ".")
            break;

        int j = 0;
        for (int i = 1; i < s.length(); i++)
        {
            p[i] = 0;
            while (j > 0 && s[i] != s[j])
                j = p[j - 1];
            if (s[i] == s[j])
                p[i] = ++j;
        }

        int dist = s.length() - p[s.length() - 1];
        if (s.length() % dist != 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << s.length() / dist << "\n";
        }
    }
    return 0;
}
