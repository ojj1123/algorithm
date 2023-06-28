// BFS 거리측정
// 한 숫자씩 받을 때 scanf("%1d", %a[i]) 사용
// NOTE: ios::sync_with_stdio(0) 사용하면 c 입출력 함수와 동기화를 끊음

#include <bits/stdc++.h>
using namespace std;

string board[102];
int vis[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, -1);

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != '1' || vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << vis[n - 1][m - 1];
    return 0;
}