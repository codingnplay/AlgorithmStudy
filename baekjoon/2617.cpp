#include <iostream>
#include <vector>

using namespace std;

typedef struct marble {
	bool visited;
	vector<int> next_marbles;
	vector<int> previous_marbles;
};

vector<marble> Marbles;
int N, M;

int next_dfs(int n) {
	int count = 1;
	int i;
	Marbles[n].visited = true;
	for (i = 0; i < Marbles[n].next_marbles.size(); i++) {
		if (!Marbles[Marbles[n].next_marbles[i]-1].visited) { count += next_dfs(Marbles[n].next_marbles[i]- 1); }
	}
	return count;
}

int previous_dfs(int n) {
	int count = 1;
	int i;
	Marbles[n].visited = true;
	for (i = 0; i < Marbles[n].previous_marbles.size(); i++) {
		if (!Marbles[Marbles[n].previous_marbles[i] - 1].visited) count += previous_dfs(Marbles[n].previous_marbles[i] - 1);
	}
	return count;
}


int main()
{
	int i, j;
	cin >> N >> M;
	int ans = 0;

	for (i = 0; i < N; i++) {
		marble new_marble;
		Marbles.push_back(new_marble);
	}

	for (i = 0; i < M; i++) {
		int next, x;
		cin >> next >> x;
		Marbles[x - 1].next_marbles.push_back(next);
		Marbles[next - 1].previous_marbles.push_back(x);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			Marbles[j].visited = false;
		}

		if (next_dfs(i) > (N + 1) / 2) ans += 1;
		else {
			for (j = 0; j < N; j++) {
				Marbles[j].visited = false;
			}
			if (previous_dfs(i) > (N + 1) / 2) ans += 1;
		}
	}

	cout << ans;
}
