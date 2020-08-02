#include <iostream>
#include <list>

using namespace std;

int F, S, G, U, D;
int value[1000001];
bool visited[1000001];
list<int> BFSQueue;

void bfs() {
	if (BFSQueue.empty()) return;
	int x = BFSQueue.front();
	BFSQueue.pop_front();

	if (x == G) return;
	if (x + U <= F && !visited[x+U]) {
		BFSQueue.push_back(x + U);
		visited[x + U] = true;
		value[x + U] = value[x] + 1;
	}
	if (x - D > 0 && !visited[x-D]) {
		BFSQueue.push_back(x - D);
		visited[x - D] = true;
		value[x - D] = value[x] + 1;
	}
	bfs();
}

int main()
{
	cin >> F >> S >> G >> U >> D;

	visited[S] = true;
	BFSQueue.push_back(S);
	bfs();

	if (visited[G]) {
		cout << value[G];
	}
	else {
		cout << "use the stairs";
	}
	return 0;
}
