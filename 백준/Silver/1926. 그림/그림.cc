#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];
	queue<pair<int, int>> q;
	int picCnt = 0, size, res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				q.push({ i,j });
				vis[i][j] = 1;
				picCnt++;
				size = 0;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					size++;
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				res = max(res, size);
			}
		}
	}
	cout << picCnt << "\n" << res;
	return 0;
}