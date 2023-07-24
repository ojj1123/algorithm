#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
#define endl '\n'

int board[11][11];
bool isUsed1[11][11];
bool isUsed2[11][11];
bool isUsed3[11][11];
vector<pair<int, int>> zero;

int n, cnt;

void init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				zero.push_back({ i, j });
			} else {
				isUsed1[i][board[i][j]] = true;
				isUsed2[j][board[i][j]] = true;
				isUsed3[3 * (i / 3) + (j / 3)][board[i][j]] = true;
			}
		}
	}
	n = zero.size();
}

void output() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void solve(int cur, int k) {
	if (cnt >= 1) return;
	if (cur >= n) {
		output();
		cnt++;
		return;
	}

	auto h = zero[cur];
	int squreIdx = 3 * (h.X / 3) + (h.Y / 3);

	for (int j = 1; j <= 9; j++) {
		if (isUsed1[h.X][j] || isUsed2[h.Y][j] || isUsed3[squreIdx][j] || board[h.X][h.Y] != 0) continue;
		isUsed1[h.X][j] = 1;
		isUsed2[h.Y][j] = 1;
		isUsed3[squreIdx][j] = 1;
		board[h.X][h.Y] = j;
		solve(cur + 1, j);
		isUsed1[h.X][j] = 0;
		isUsed2[h.Y][j] = 0;
		isUsed3[squreIdx][j] = 0;
		board[h.X][h.Y] = 0;
	}
}


int main() {
	init();
	solve(0, 1);
}