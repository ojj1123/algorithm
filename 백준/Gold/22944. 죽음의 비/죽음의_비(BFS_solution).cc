// BFS 풀이
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 500;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, h, d;
int startX, startY;
char board[MAX + 2][MAX + 2];
bool vis[12][MAX + 2][MAX + 2];

void init();
void solve();

struct Node {
    int x;
    int y;
    int hp;
    int umbIdx;
    int umb;
    int dist;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> n >> h >> d;
    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == 'S') {
                startX = i;
                startY = j;
            }
            board[i][j] = temp;
        }
    }
}

void solve() {
    queue<Node> q;
    int nUmbIdx = 0;

    vis[0][startX][startY] = true;
    // {x, y, hp, umbIdx, umb, dist}
    q.push({startX, startY, h, 0, 0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nUmb = cur.umb;
            int nHp = cur.hp;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[cur.umbIdx][nx][ny]) continue;

            if (board[nx][ny] == 'E') {
                cout << cur.dist + 1 << endl;
                return;
            }

            if (board[nx][ny] == '.') {
                if (nUmb == 0) {
                    nHp--;
                } else {
                    nUmb--;
                }
            } else if (board[nx][ny] == 'U') {
                // 우산 있는 곳도 비 맞음
                nUmb = d - 1;
                cur.umbIdx = ++nUmbIdx;
                board[nx][ny] = '.';
            }

            if (nHp == 0) continue;
            vis[cur.umbIdx][nx][ny] = true;
            // {x, y, hp, umbIdx, umb, dist}
            q.push({nx, ny, nHp, cur.umbIdx, nUmb, cur.dist + 1});
        }
    }

    cout << -1 << endl;
}
