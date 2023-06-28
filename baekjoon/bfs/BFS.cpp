// BFS 에 틀이되는 코드

#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    return 0;
}