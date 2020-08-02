#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int N, M;
int board[500][500];
int ans = 0;

void shape1() {
	int i, j, tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 3; j++) {
			tmp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (ans < tmp) ans = tmp;
		}
	}

	for (i = 0; i < N - 3; i++) {
		for (j = 0; j < M; j++) {
			tmp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (ans < tmp) ans = tmp;
		}
	}
}

void shape2() {
	int i, j, tmp;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
			if (ans < tmp)ans = tmp;
		}
	}
}

void shape3() {
	int i, j, tmp;
	for (i = 0; i < N - 2; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i][j];
			if (ans < tmp)ans = tmp;
		}
	}

	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < M - 2; j++) {
			tmp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
			if (ans < tmp)ans = tmp;
			tmp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j];
			if (ans < tmp)ans = tmp;
			tmp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
			if (ans < tmp)ans = tmp;
		}
	}
}

void shape4() {
	int i, j, tmp;
	for (i = 0; i < N - 2; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j] + board[i + 2][j];
			if (ans < tmp)ans = tmp;
		}
	}
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < M - 2; j++) {
			tmp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (ans < tmp)ans = tmp;
			tmp = board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2];
			if (ans < tmp)ans = tmp;
		}
	}
}

void shape5() {
	int i, j, tmp;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < M - 2; j++) {
			tmp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
			if (ans < tmp)ans = tmp;
			tmp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 1];
			if (ans < tmp)ans = tmp;
		}
	}
	for (i = 0; i < N - 2; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
			if (ans < tmp)ans = tmp;
			tmp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 1][j];
			if (ans < tmp)ans = tmp;
		}
	}
}

int main()
{
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	shape1();
	shape2();
	shape3();
	shape4();
	shape5();

	cout << ans;
	return 0;
}
