#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int N;
int A[1000001];
int P[1000001];
vector<int> ans;
vector<int> pos;
vector<int> queue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int i;
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	ans.push_back(A[0]);
	pos.push_back(0);
	P[0] = -1;

	for (i = 1; i < N; i++) {
		if (ans.back() < A[i]) {
			P[i] = pos.back();
			ans.push_back(A[i]);
			pos.push_back(i);
		}
		else {
			int po = lower_bound(ans.begin(), ans.end(), A[i]) - ans.begin();
			ans[po] = A[i];
			pos[po] = i;
			if (po == 0) P[i] = -1;
			else {
				P[i] = pos[po - 1];
			}
		}
	}

	std::cout << ans.size() << "\n";
	int a = pos.back();
	while (a != -1) {
		queue.push_back(A[a]);
		a = P[a];
	}

	while (!queue.empty()) {
		cout << queue.back() << " ";
		queue.pop_back();
	}

	return 0;
}
