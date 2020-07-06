#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int N, M, startNum;

typedef struct node {
	bool visited;
	vector<int> next;
};

vector<node> Nodes;
list<int> BFSQueue;

void dfs(int x) {
	cout << x << " ";
	Nodes[x].visited = true;
	for (int i = 0; i < Nodes[x].next.size(); i++) {
		if (!Nodes[Nodes[x].next[i]].visited) dfs(Nodes[x].next[i]);
	}
}

void bfs() {
	if (!BFSQueue.empty()) {
		int x = BFSQueue.front();
		BFSQueue.pop_front();
		for (int a : Nodes[x].next) {
			if (!Nodes[a].visited) {
				Nodes[a].visited = true;
				cout << a << " ";
				BFSQueue.push_back(a);
			}
		}
		bfs();
	}
}

int main()
{
	cin >> N >> M >> startNum;

	int i;
	for (i = 0; i < N + 1; i++) {
		node new_node;
		Nodes.push_back(new_node);
	}

	for (i = 0; i < M; i++) {
		int tempx, tempy;
		cin >> tempx >> tempy;
		Nodes[tempx].next.push_back(tempy);
		Nodes[tempy].next.push_back(tempx);
	}

	for (i = 0; i < N + 1; i++) {
		if(!Nodes[i].next.empty()) sort(Nodes[i].next.begin(), Nodes[i].next.end());
		Nodes[i].visited = false;
	}

	dfs(startNum); cout << "\n";
	for (i = 0; i < N + 1; i++) {
		Nodes[i].visited = false;
	}

	BFSQueue.push_back(startNum);
	cout << startNum << " ";
	Nodes[startNum].visited = true;
	bfs();
}
