#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'
#define X first
#define Y second

int n, m;
char board[52][52];
int dist[52][52];
bool vis[52][52];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool flag;

void init();
void solve();
int dfs(int, int);
int ctoi(char);

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
}

void solve() {
    cout << dfs(0, 0);
}

int dfs(int x, int y) {
    int ret = dist[x][y];
    if (ret != 0) return ret;

    vis[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir] * ctoi(board[x][y]);
        int ny = y + dy[dir] * ctoi(board[x][y]);
        // 범위를 벗어난 경우
        if (board[nx][ny] == 'H' || (nx < 0 || nx >= n || ny < 0 || ny >= m)) {
            ret = max(ret, dist[x][y]);
            continue;
        }
        // 이미 방문한 경우 -> 무한 순환
        if (vis[nx][ny]) {
            cout << -1;
            exit(0);
        }

        ret = max(ret, dfs(nx, ny));
    }

    // 자식까지 다 돌고 옴
    vis[x][y] = false;
    dist[x][y] = ret + 1;
    return ret + 1;
}

int ctoi(char c) {
    return c - '0';
}