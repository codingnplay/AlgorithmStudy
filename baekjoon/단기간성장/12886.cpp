#include <iostream>
#include <queue>
using namespace std;

struct node {
	int i[2];
};

bool visited[1501][1501];
queue<node> bfsQueue;
int A, B, C;
int sum;

void sort3(int* a, int* b, int* c) {
	if (*a >= * c && *a >= * b) {
		swap(*a, *c);
	}
	else if (*b >= * c && *b >= * a) {
		swap(*b, *c);
	}
	if (*a >= * b) {
		swap(*a, *b);
	}
}

int main()
{
	cin >> A >> B >> C;
	if ((A + B + C) % 3 != 0) {
		cout << "0\n";
		return 0;
	}

	sort3(&A, &B, &C);
	sum = A + B + C;
	bfsQueue.push({ A,C});
	visited[A][C] = true;

	while (!bfsQueue.empty()) {
		node newnode = bfsQueue.front();
		bfsQueue.pop();

		if (newnode.i[0] == newnode.i[1]) {
			cout << "1\n";
			return 0;
		}

		cout << "[" << newnode.i[0] << " " << sum - newnode.i[0] - newnode.i[1] << " " << newnode.i[1] << "]\n";

		int tmp1, tmp2, tmp3;

		if (newnode.i[0] != sum - newnode.i[0] - newnode.i[1]) {
			tmp1 = newnode.i[0] * 2;
			tmp2 = sum - newnode.i[0] - newnode.i[1] - newnode.i[0];
			tmp3 = newnode.i[1];
			sort3(&tmp1, &tmp2, &tmp3);
			if (!visited[tmp1][tmp3] && tmp3 <= 1500) {
				cout << tmp1 << " " << tmp2 << " " << tmp3 << "\n";
				visited[tmp1][tmp3] = true;
				bfsQueue.push({ tmp1, tmp3 });
			}
		}
		if (newnode.i[2] != sum - newnode.i[0] - newnode.i[1]) {
			tmp1 = (sum - newnode.i[0] - newnode.i[1]) * 2;
			tmp2 = newnode.i[1] - (sum - newnode.i[0] - newnode.i[1]);
			tmp3 = newnode.i[0];
			sort3(&tmp1, &tmp2, &tmp3);
			cout << tmp1 << " " << tmp2 << " " << tmp3 << "\n";
			if (!visited[tmp1][tmp3] && tmp3 <= 1500) {
				visited[tmp1][tmp3] = true;
				bfsQueue.push({ tmp1,tmp3 });
			}
		}
		if (newnode.i[0] != newnode.i[1]) {
			tmp1 = newnode.i[0] * 2;
			tmp2 = newnode.i[1] - newnode.i[0];
			tmp3 = sum - newnode.i[0] - newnode.i[1];
			sort3(&tmp1, &tmp2, &tmp3);
			if (!visited[tmp1][tmp3]&& tmp3 <= 1500) {
				cout << tmp1 << " " << tmp2 << " " << tmp3 << "\n";
				visited[tmp1][tmp3] = true;
				bfsQueue.push({ tmp1,tmp3 });
			}
		}
	}

	cout << "0\n";
	return 0;
}
