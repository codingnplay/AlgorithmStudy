#include <iostream>
#include <vector>
using namespace std;

string str;
vector<node> stack;
int ans = 0;

class node{
    public:
        bool isValue;
        int value;
        char c;
    
    node(int v){
        isValue = true;
        value = v;
    }
    
    node(char par){
        isValue = false;
        c = par;
    }
};

int main()
{
	cin >> str;
	int i;
	bool valid = true;

	for (i = 0; i < str.size() && valid; i++) {
		int sum = 0;
		char c;
		if (str[i] == '(' || str[i] == '[') stack.push_back(str[i]);
		else if (str[i] == ')') {
			while (stack.size() > 0) {
				c = stack.back();
				stack.pop_back();
				if (c == '(') {
					if (sum == 0) {
						stack.push_back(2);
					}
					else {
						stack.push_back(sum * 2);
					}
					break;
				}
				else if (c == '[') {
					valid = false;
					break;
				}
				else {
					sum += c;
				}
			}
		}
		else if (str[i] == ']'){
			while (stack.size() > 0) {
				c = stack.back();
				stack.pop_back();
				if (c == '[') {
					if (sum == 0) {
						stack.push_back(3);
					}
					else {
						stack.push_back(sum * 3);
					}
					break;
				}
				else if (c == '(') {
					valid = false;
					break;
				}
				else {
					sum += c;
				}
			}
		}
	}

	int ans = 0;
	while (stack.size() > 0) {
		char c = stack.back();
		stack.pop_back();
		if (c == '(' || c == '[') {
			cout << '0'; break;
		}
		else {
			ans += c;
		}
	}

	cout << ans;
	
	return 0;
}
