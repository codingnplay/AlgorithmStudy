#include <iostream>
#include <list>

using namespace std;

int wheel[4][8];
int prewheel[4][8];
int N;
int** simul;

void clockwise(int idx) {
	int tmp = wheel[idx][7];
	for (int i = 7; i > 0; i--) {
		wheel[idx][i] = wheel[idx][i - 1];
	}
	wheel[idx][0] = tmp;
}

void counterclockwise(int idx) {
	int tmp = wheel[idx][0];
	for (int i = 0; i < 7; i++) {
		wheel[idx][i] = wheel[idx][i + 1];
	}
	wheel[idx][7] = tmp;
}

int main()
{
	int i, j;
	for (i = 0; i < 4; i++) {
		string tmp;
		cin >> tmp;
		for (j = 0; j < 8; j++) {
			if (tmp[j] == '0') wheel[i][j] = 0;
			else wheel[i][j] = 1;
		}
	}

	cin >> N;
	simul = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++) {
		simul[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < 2; j++) {
			cin >> simul[i][j];
		}
	}

	//    2/6 -2/6 -2/6

	for (i = 0; i < N; i++) {

		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 8; y++) {
				prewheel[x][y] = wheel[x][y];
			}
		}

		int idx = simul[i][0] - 1;
		int dir = simul[i][1];
		if (dir == 1) {
			clockwise(idx);
		}
		else {
			counterclockwise(idx);
		}

		int previous_dir = dir;
		for (j = idx + 1; j < 4; j++) {
			if (prewheel[j - 1][2] == prewheel[j][6]) break;
			else {
				if (previous_dir == 1) {
					counterclockwise(j);
					previous_dir = -1;
				}
				else {
					clockwise(j);
					previous_dir = 1;
				}
			}
		}

		previous_dir = dir;
		for (j = idx - 1; j >= 0; j--) {
			if (prewheel[j][2] == prewheel[j + 1][6]) break;
			else {
				if (previous_dir == 1) {
					counterclockwise(j);
					previous_dir = -1;
				}
				else {
					clockwise(j);
					previous_dir = 1;
				}
			}
		}
	}

	int score = 0;
	if (wheel[0][0] == 1) score += 1;
	if (wheel[1][0] == 1) score += 2;
	if (wheel[2][0] == 1) score += 4;
	if (wheel[3][0] == 1) score += 8;
	cout << score;
}
