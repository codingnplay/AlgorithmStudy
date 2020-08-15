#include <iostream>
#include <vector>
using namespace std;

string str;
vector<char> stack;

int main()
{
    cin >> str;
    int i;
    for (i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            cout << str[i];
        }
        else if (str[i] == '(') {
            stack.push_back(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-') {
            while (!stack.empty() && (stack.back() == '+' || stack.back() == '-' || stack.back() == '*' || stack.back() == '/')) {
                cout << stack.back();  stack.pop_back();
            }
            stack.push_back(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/') {
            while (!stack.empty() && (stack.back() == '*' || stack.back()=='/')) {
                cout << stack.back();  stack.pop_back();
            }
            stack.push_back(str[i]);
        }
        else {
            while (!stack.empty() && stack.back() != '(') {
                cout << stack.back();  stack.pop_back();
            }
            if (!stack.empty() && stack.back() == '(') {
                stack.pop_back();
            }
        }
    }

    while (!stack.empty()) {
        cout << stack.back();
        stack.pop_back();
    }
    return 0;
}
