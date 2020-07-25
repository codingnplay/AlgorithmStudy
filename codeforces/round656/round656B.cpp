#include <iostream>
#include <vector>

using namespace std;
int T, N;
vector<int> Ns;
vector<vector<int>> cases;
vector<vector<int>> answers;
int idxX, idxY;

int main()
{
	int i, t;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		Ns.push_back(N);
		vector<int> element(N * 2);
		cases.push_back(element);
		int tmp;
		for (i = 0; i < N * 2; i++) {
			cin >> cases[t][i];
		}
	}

	for (t = 0; t < T; t++) {
		int ansArr[51] = { 0, };
		int tmpArr[51] = { 0, };
		idxX = 1; idxY = 0;
		ansArr[0] = cases[t][0];
		tmpArr[0] = cases[t][0];

		for (i = 1; i < Ns[t] * 2; i++) {
			if (cases[t][i] == tmpArr[idxY]) {
				idxY++;
			}
			else {
				ansArr[idxX] = cases[t][i];
				tmpArr[idxX] = cases[t][i];
				idxX++;
			}
		}

		vector<int> element(Ns[t]);
		answers.push_back(element);
		for (i = 0; i < Ns[t]; i++) {
			answers[t][i] = ansArr[i];
		}
		
	}

	for (t = 0; t < T; t++) {
		for (int x : answers[t]) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}