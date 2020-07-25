#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef struct whereIsApple {
	int x;
	int y;
};

typedef struct rotation {
	int time;
	char dir;
};

typedef struct snakeBody {
	int x;
	int y;
	char dir; //'S' 'N' 'W' 'E'
};

int N, K, L;
vector<whereIsApple> apples;
list<rotation> rotations;
int seconds = 0;

class SnakeBody {

public :

	list<snakeBody> Snake;

	SnakeBody() {
		snakeBody newSnakeBody;
		newSnakeBody.x = 1;
		newSnakeBody.y = 1;
		newSnakeBody.dir = 'E';
		Snake.push_front(newSnakeBody);
	}

	bool isApple(int x, int y) {

		for (vector<whereIsApple>::iterator i = apples.begin(); i != apples.end(); i++) {
			if (i->x == x && i->y == y) {
				apples.erase(i);
				return true;
			}
		}

		return false;
	}

	int push_front_new_body() {
		snakeBody head = Snake.front();

		int i, j;

		switch(head.dir) {
		case 'E':
			i = head.x;
			j = head.y + 1;
			break;
		case 'N':
			i = head.x - 1;
			j = head.y;
			break;
		case 'S':
			i = head.x + 1;
			j = head.y;
			break;
		case 'W':
			i = head.x;
			j = head.y - 1;
			break;
		}

		if (i <= 0 || i > N || j <= 0 || j > N) {
			return -1;
		}
		for (list<snakeBody>::iterator x = Snake.begin(); x != Snake.end(); x++) {
		
			if (i == x->x && j == x->y) {
				return -1;
			}
		}

		snakeBody newHead;
		newHead.x = i;
		newHead.y = j;
		newHead.dir = Snake.front().dir;

		seconds += 1;

		if (!rotations.empty()) {
			if (rotations.front().time == seconds) {
				if (rotations.front().dir == 'D') {
					switch (newHead.dir) {
					case 'N': newHead.dir = 'E'; break;
					case 'S': newHead.dir = 'W'; break;
					case 'E': newHead.dir = 'S'; break;
					case 'W': newHead.dir = 'N'; break;
					}
				}
				else {
					switch (newHead.dir) {
					case 'N': newHead.dir = 'W'; break;
					case 'S': newHead.dir = 'E'; break;
					case 'E': newHead.dir = 'N'; break;
					case 'W': newHead.dir = 'S'; break;
					}
				}
				rotations.pop_front();
			}
		}

		Snake.push_front(newHead);

		if (!isApple(i, j)) {
			Snake.pop_back();
		}

		return 1;
	}

	void print() {
	
		cout << "print snake\n";
		for (snakeBody iter : Snake) {
			cout << iter.x << " " << iter.y << " " << iter.dir << "\n";
		}
		cout << "print apple\n";
		for (whereIsApple apple : apples) {
			cout << apple.x << " " << apple.y << "\n";
		}
		cout << "print directions\n";
		for (rotation rotation : rotations) {
			cout << rotation.time << " " << rotation.dir << "\n";
		}
		cout << "print seconds\n" << seconds << "\n";

	}
};


int main()
{
	int i, j;
	cin >> N >> K;

	for (i = 0; i < K; i++) {
		whereIsApple newApple;
		cin >> newApple.x >> newApple.y;
		apples.push_back(newApple);
	}
	cin >> L;
	for (i = 0; i < L; i++) {
		rotation newRotation;
		cin >> newRotation.time >> newRotation.dir;
		rotations.push_back(newRotation);
	}


	SnakeBody snakeBody;

	while (1) {

		if (snakeBody.push_front_new_body() == -1) break;
	}

	cout << seconds + 1 << "\n";
}
