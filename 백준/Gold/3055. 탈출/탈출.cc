#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second
#define endl '\n'

char board[51][51];
int waterFill[51][51];
int vis[51][51];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int r, c;
queue<pair<int, int>> waterQ, eriQ;

void init() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		fill(vis[i], vis[i] + c + 1, -1);
		fill(waterFill[i], waterFill[i] + c + 1, -1);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*') {
				waterFill[i][j] = 0;
				waterQ.push({ i, j });
			}
			else if (board[i][j] == 'S') {
				eriQ.push({ i, j });
				vis[i][j] = 0;
			};
		}
	}
	
}
int main() {
	init();

	
	while (!waterQ.empty()) {
		auto cur = waterQ.front();
		waterQ.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;
			if (waterFill[nx][ny] != -1) continue;
			waterQ.push({ nx,ny });
			waterFill[nx][ny] = waterFill[cur.X][cur.Y] + 1;
		}
	}

	while (!eriQ.empty()) {
		auto cur = eriQ.front();
		eriQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'X' || (waterFill[nx][ny] != -1 && waterFill[nx][ny] <= vis[cur.X][cur.Y] + 1)) continue;
			if (vis[nx][ny] != -1) continue;
			eriQ.push({ nx,ny });
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			if (board[nx][ny] == 'D') {
				cout << vis[nx][ny];
				return 0;
			}
		}
	}

	
	cout << "KAKTUS";
}