#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'
#define X first
#define Y second

int n, m;
int board[1002][1002];
int vis[1002][1002];
unordered_map<int, int> area;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;
int num;

void init();
void solve();
void bfs(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + m + 1, -1);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 이미 방문했거나 0인 영역이라면
            if (vis[i][j] != -1 || board[i][j] == 0) continue;

            bfs(i, j);

            area.insert({num, cnt});
        }
    }

    int ans = 0;

    unordered_map<int, bool> checkMap;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) continue;
            int sum = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                int areaNum = vis[nx][ny];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (areaNum == -1) continue;
                // 해당 영역은 이미 추가했다면
                if (checkMap.find(areaNum) != checkMap.end()) continue;
                // 해당 영역 추가안했으므로 추가
                checkMap.insert({areaNum, true});
                sum += area[areaNum];
            }

            checkMap.clear();
            ans = max(ans, sum);
        }
    }

    cout << ans + 1;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;

    num++;
    cnt = 0;
    vis[x][y] = num;
    q.push({x, y});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 1 인 영역이 아니면
            if (board[nx][ny] == 0) continue;
            // 이미 방문했다면
            if (vis[nx][ny] != -1) continue;
            q.push({nx, ny});
            vis[nx][ny] = num;
        }
    }
}