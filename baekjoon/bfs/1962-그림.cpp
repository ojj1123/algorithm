// BFS Flod fiil 예제
#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int mx = 0, cnt = 0;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int, int>> q;
            int tmp = 1;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    tmp++;
                }
            }
            mx = max(mx, tmp);
            cnt++;
        }
    }
    cout << cnt << '\n'
         << mx;
    return 0;
}