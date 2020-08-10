#include <iostream>
#include <algorithm>
using namespace std;
//a, n, t, c, i

int L, C;
bool visited[26] = { false, };
char A[26];
int selected = 0;
int vowel = 0, consonant = 0;

void dfs(int idx) {
	visited[A[idx] - 'a'] = true;
	selected++;
	int i;
	i = A[idx] - 'a';

	if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' || 'a' + i == 'o' || 'a' + i == 'u') {
		vowel++;
	}
	else {
		consonant++;
	}

	if (selected == L) {
		if (vowel >= 1 && consonant >= 2) {
			for (i = 0; i < 26; i++) {
				if (visited[i]) {
					printf("%c", 'a' + i);
				}
			}
			cout << "\n";
		}
	}
	else {
		for (i = idx + 1; i < C; i++) {
			if (!visited[A[i] - 'a']) {
				dfs(i);
			}
		}
	}

	visited[A[idx] - 'a'] = false;
	selected--;

	i = A[idx] - 'a';
	if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' || 'a' + i == 'o' || 'a' + i == 'u') {
		vowel--;
	}
	else {
		consonant--;
	}
}

int main()
{
	cin >> L >> C;
	int i;
	for (i = 0; i < C; i++) {
		cin >> A[i];
	}

	sort(A, A + C);

	for (i = 0; i < C; i++) {
		dfs(i);
	}
	return 0;
}
