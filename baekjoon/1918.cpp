#include <iostream>
#include <vector>

using namespace std;

vector<char> stack;

int main()
{
	string str;
	cin >> str;
	int i; char c;
	for (i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
		else if (str[i] == ')') {
			while (!stack.empty()) {
				c = stack.back();
				stack.pop_back();
				if (c != '(') cout << c;
				else {
					break;
				}
			}
		}
		else if (str[i] == '+' || str[i] == '|') {
			if(!stack.empty()){
				if (stack.back() == '*' || stack.back() == '/') {
					while (!stack.empty()) {
						c = stack.back();
						if (c != '+' && c != '-') {
							stack.pop_back();
							if (c != '(') cout << c;
						}
						else {
							break;
						}
					}
				}
			}
			stack.push_back(str[i]);
		}
		else {
			if (!stack.empty()) {
				if (stack.back() == '*' || stack.back() == '/') {
					while (!stack.empty()) {
						c = stack.back();
						if (c != '+' && c != '-') {
							stack.pop_back();
							if (c != '(') cout << c;
						}
						else {
							break;
						}
					}
				}
			}
			stack.push_back(str[i]);
		}
	}

	while (!stack.empty()) {
		c = stack.back();
		stack.pop_back();
		if (c != '(') cout << c;
	}
	return 0;
}
