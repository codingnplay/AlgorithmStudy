#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct node {
	bool visited;
	list<int> next;
};

int N, K;
list<int> bfsQueue;
vector<node> Node;

int bfs() {

	if (bfsQueue.empty()) return 0;
	
	int count = 0;
	int x = bfsQueue.front();
	bfsQueue.pop_front();

	for (int i : Node[x].next) {
		if (!Node[i].visited) {
			count++;
			Node[i].visited = true;
			bfsQueue.push_back(i);
		}
	}

	return count + bfs();

}

int main()
{
	int i;
	cin >> N >> K;
	for (i = 0; i < N+1; i++) {
		node new_node;
		new_node.visited = false;
		Node.push_back(new_node);
	}

	for (i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		Node[x].next.push_back(y);
		Node[y].next.push_back(x);
	}

	Node[1].visited = true;
	bfsQueue.push_back(1);
	int ans = bfs();
	cout << ans;
}
