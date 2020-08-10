#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
list<pair<int, int>> picQueue;
vector<int> likeQueue;
int like[101] = { 0, };
int time = 0;

bool comp(pair<int, int> aPic, pair<int, int> bPic) {
	if (like[aPic.first] != like[bPic.first]) {
		return like[aPic.first] < like[bPic.first];
	}
	return aPic.second < bPic.second;
}

bool comp2(pair<int, int> aPic, pair<int, int> bPic) {
	return aPic.first < bPic.first;
}

void solve(int stu) {

	for (pair<int,int> pic : picQueue) {
		if (pic.first == stu) {
			like[stu]++;
			return;
		}
	}

	if (picQueue.size() < N) {
		picQueue.push_back(make_pair(stu, time));
		like[stu] = 1;
	}
	else {
		picQueue.sort(comp);
		picQueue.pop_front();
		picQueue.push_back(make_pair(stu,time));
		like[stu] = 1;
	}
}

int main()
{
	cin >> N >> M;
	int i, j;
	for (i = 0; i < M; i++) {
		cin >> j;
		time++;
		solve(j);
	}

	if(!picQueue.empty()) picQueue.sort(comp2);

	for (pair<int,int> pic : picQueue) {
		cout << pic.first << " ";
	}
	return 0;
}
