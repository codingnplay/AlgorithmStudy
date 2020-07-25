#include <iostream>
#include <vector>
#include <list>

using namespace std;
int N;
int A, B;
vector<int> relatives[100];
int b[100];
bool visited[100];
list<int> bfsQueue;
int ans = -1;

void bfs() {
	if (bfsQueue.empty()) return;
	int x = bfsQueue.front(); bfsQueue.pop_front();
	for (int r : relatives[x]) {
		if (!visited[r]) {
			visited[r] = true;
			if (r == B - 1) {
				ans = b[x] + 1;
				return;
			}
			else {
				b[r] = b[x] + 1;
				bfsQueue.push_back(r);
			}
		}
	}

	bfs();
}

int main()
{
	cin >> N >> A >> B;

	int i, n, x, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		relatives[x - 1].push_back(y - 1);
		relatives[y - 1].push_back(x - 1);
	}

	bfsQueue.push_back(A-1);
	visited[A - 1] = true;
	bfs();

	cout << ans;
}
