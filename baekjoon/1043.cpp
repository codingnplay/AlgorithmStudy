#include <iostream>
#include <vector>

using namespace std;

int N, M, A, B;
vector<int> factKnows;
vector<vector<int>> parties;
vector<vector<int>> ppl;
bool visited[51];
bool partyVisited[51];

void mark(int);

void Pmark(int p) {
	partyVisited[p] = true;
	for (int n : parties[p]) {
		if (!visited[n]) {
			mark(n);
		}
	}
}

void mark(int n) {
	visited[n] = true;
	for (int party : ppl[n]) {
		if(!partyVisited[party]){
			Pmark(party);
		}
	}
}

int main()
{
	cin >> N >> M;
	
	cin >> A;
	int i, j, tmp;

	for (i = 0; i <= N; i++) {
		vector<int> person;
		ppl.push_back(person);
	}
	
	for (i = 0; i < A; i++) {
		cin >> tmp;
		factKnows.push_back(tmp);
	}

	for (i = 0; i < M; i++) {
		cin >> B;
		vector<int> party;
		parties.push_back(party);
		for (j = 0; j < B; j++) {
			cin >> tmp;
			parties[i].push_back(tmp);
			ppl[tmp].push_back(i);
		}
	}

	for (int know : factKnows) {
		if(!visited[know])
			mark(know);
	}

	int ans = 0;

	for (i = 0; i < M; i++) {
		if (!partyVisited[i]) ans++;
	}
	cout << ans;
	
	return 0;
}
