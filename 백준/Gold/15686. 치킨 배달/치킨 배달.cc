#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
#define endl '\n'
const int INF = 10e9;

int board[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool isCheckChicken[14];
int chickenCnt, houseCnt;
int n, m;
int ans = INF;

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i, j });
			if (board[i][j] == 2) chicken.push_back({ i, j });
		}
	}
	chickenCnt = chicken.size();
	houseCnt = house.size();
}

int dist(int ax, int ay, int bx, int by) {
	return abs(ax - bx) + abs(ay - by);
}

int calculateTotalCityChickenDist() {
	int sum = 0;
	for (int i = 0; i < houseCnt; i++) {
		int minDist = INF;
		for (int j = 0; j < chickenCnt; j++) {
			if (!isCheckChicken[j]) continue;
			int distance = dist(house[i].X, house[i].Y, chicken[j].X, chicken[j].Y);
			minDist = min(minDist, distance);
		}
		sum += minDist;
	}
	
	return sum;
}

void selectChicken(int cnt, int cur) {
	if (cnt >= m) {
		// 도시 치킨 거리 구하기
		ans = min(ans, calculateTotalCityChickenDist());
		return;
	}
	for (int i = cur; i < chickenCnt; i++) {
		if (isCheckChicken[i]) continue;
		isCheckChicken[i] = true;
		selectChicken(cnt + 1, i + 1);
		isCheckChicken[i] = false;
	}
}


int main() {
	init();
	selectChicken(0, 0);
	cout << ans;
}