// 아직 미완성

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int** board;
bool** visited;
bool** visited2;
int N;
int L, R;
int MoveCount = 0;

int subtract(int x, int y) {
	if (x > y) return x - y;
	else return y - x;
}

bool checkLR(int x, int y) {
	if (subtract(x, y) >= L && subtract(x, y) <= R) return true;
	return false;
}

bool boundaryOpen() {
	int i, j;
	bool returnValue = false;

	for (i = 0; i < 2*N + 1; i++) {
		for (j = 0; j < 2*N + 1; j++) {
			visited[i][j] = true;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i!=N-1 && checkLR(board[i + 1][j], board[i][j])) {
				visited[2*i][2*j] = false;
				visited[2 * i + 1][2 * j] = false;
				visited[2*(i + 1)][2*j] = false;
				returnValue = true;
			}
			if (j != N-1 && checkLR(board[i][j + 1], board[i][j])) {
				visited[2*i][2*j] = false;
				visited[2 * i][2 * j + 1] = false;
				visited[2*i][2*(j + 1)] = false;
				returnValue = true;
			}
		}
	}

	return returnValue;
}

int dfs_how_many_country(int startI, int startJ, bool** visited) {
	int country = 1;

	visited[2*startI][2*startJ] = true;

	if (!visited[2 * startI + 1][2 * startJ]) {
		visited[2 * startI + 1][2 * startJ] = true;
		country += dfs_how_many_country(startI + 1, startJ, visited);
	}
	if (!visited[2 * startI][2 * startJ + 1]) {
		visited[2 * startI][2 * startJ + 1] = true;
		country += dfs_how_many_country(startI, startJ + 1, visited);
	}
	if (startI != 0 && !visited[2 * startI - 1][2 * startJ]) {
		visited[2 * startI - 1][2 * startJ] = true;;
		country += dfs_how_many_country(startI - 1, startJ, visited);
	}
	if (startJ != 0 && !visited[2 * startI][2 * startJ - 1]) {
		visited[2 * startI][2 * startJ - 1] = true;
		country += dfs_how_many_country(startI, startJ - 1, visited);
	}	

	return country;
}

int dfs_return_pop(int startI, int startJ, bool** visited) {

	int pop = board[startI][startJ];
	visited[2 * startI][2 * startJ] = true;

	if (!visited[2 * startI + 1][2 * startJ]) {
		visited[2 * startI + 1][2 * startJ] = true;
		pop += dfs_return_pop(startI + 1, startJ, visited);
	}
	if (!visited[2 * startI][2 * startJ + 1]) {
		visited[2 * startI][2 * startJ + 1] = true;
		pop += dfs_return_pop(startI, startJ + 1, visited);
	}
	if (startI != 0 && !visited[2 * startI - 1][2 * startJ]) {
		visited[2 * startI - 1][2 * startJ] = true;;
		pop += dfs_return_pop(startI - 1, startJ, visited);
	}
	if (startJ != 0 && !visited[2 * startI][2 * startJ - 1]) {
		visited[2 * startI][2 * startJ - 1] = true;
		pop += dfs_return_pop(startI, startJ - 1, visited);
	}

	return pop;
}

void print_board();

void dfs_change_pop(int startI, int startJ, bool** visited, int value) {

	visited[2 * startI][2 * startJ] = true;
	board[startI][startJ] = value;

	if (!visited[2 * startI + 1][2 * startJ]) {
		visited[2 * startI + 1][2 * startJ] = true;
		dfs_change_pop(startI + 1, startJ, visited, value);
	}
	if (!visited[2 * startI][2 * startJ + 1]) {
		visited[2 * startI][2 * startJ + 1] = true;
		dfs_change_pop(startI, startJ + 1, visited, value);
	}
	if (startI != 0 && !visited[2 * startI - 1][2 * startJ]) {
		visited[2 * startI - 1][2 * startJ] = true;;
		dfs_change_pop(startI - 1, startJ, visited, value);
	}
	if (startJ != 0 && !visited[2 * startI][2 * startJ - 1]) {
		visited[2 * startI][2 * startJ - 1] = true;
		dfs_change_pop(startI, startJ - 1, visited, value);
	}

}

void cpy(bool** visited, bool** visited2) {
	for (int i = 0; i < 2*N + 1; i++) {
		for (int j = 0; j < 2*N + 1; j++) {
			visited2[i][j] = visited[i][j];
		}
	}
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void print_boundary() {
	for (int i = 0; i < 2*N + 1; i++) {
		for (int j = 0; j < 2*N + 1; j++) {
			cout << visited[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	int i, j;

	cin >> N >> L >> R;

	board = (int**)malloc(sizeof(int*) * (N));
	visited = (bool**)malloc(sizeof(bool*) * (2*N+ 1));
	visited2 = (bool**)malloc(sizeof(bool*) * (2*N + 1));

	for (i = 0; i < N; i++) {
		board[i] = (int*)malloc(sizeof(int) * (N));
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (i = 0; i < 2*N + 1; i++) {
		visited[i] = (bool*)malloc(sizeof(bool) * (2*N + 1));
		visited2[i] = (bool*)malloc(sizeof(bool) * (2*N + 1));
	}

	while (boundaryOpen()) {
		print_boundary();
		MoveCount++;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (!visited[2*i][2*j]) {
					cpy(visited, visited2);
					int Countries = dfs_how_many_country(i, j, visited2);
					cpy(visited, visited2);
					int Pop = dfs_return_pop(i, j, visited2);
					dfs_change_pop(i, j, visited, Pop / Countries);
					print_board();
					cout << Countries << " " << Pop << "\n";
				}
			}
		}
	}
	cout << MoveCount << "\n";
}
