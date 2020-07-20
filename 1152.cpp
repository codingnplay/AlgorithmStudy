#include <iostream>
#include <list>
using namespace std;

int N;
char sentence[1000001];
int ans = 0;

int main()
{
	cin.getline(sentence, 1000001);
	int i = 0;
	bool blank = true;

	while (sentence[i] != '\0') {
		if (sentence[i] == ' ') {
			blank = true;
		}
		else if (blank) {
			ans += 1;
			blank = false;
		}
		i++;
	}

	cout << ans;

	return 0;
}
