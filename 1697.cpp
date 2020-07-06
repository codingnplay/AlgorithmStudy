#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int N, K;
bool visited[100002];
int level[100002];
list<int> bfsQueue;
int ans;

void bfs() {

	int x = bfsQueue.front();
	bfsQueue.pop_front();

	if (x == K) {
		ans = level[x];
		return;
	}

	if (x - 1 == K || x + 1 == K || 2 * x == K) {
		ans = level[x] + 1;
		return;
	}

	if (x > 0 && !visited[x - 1]) {
		visited[x - 1] = true;
		level[x - 1] = level[x] + 1;
		bfsQueue.push_back(x - 1);
	}
	if (x < 100001 && !visited[x + 1]) {
		visited[x + 1] = true;
		level[x + 1] = level[x] + 1;
		bfsQueue.push_back(x + 1);
	}
	if (x < 50001 && !visited[2 * x]) {
		visited[2 * x] = true;
		level[2 * x] = level[x] + 1;
		bfsQueue.push_back(2 * x);
	}

	bfs();

}

int main()
{
	int i;
	for (i = 0; i < 100002; i++) visited[i] = false;
	for (i = 0; i < 100002; i++) level[i] = 0;
	cin >> N >> K;

	bfsQueue.push_back(N);
	bfs();
	cout << ans;
}
