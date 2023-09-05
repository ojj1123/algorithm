// Backtracking 풀이
// Code to here: https://github.com/tony9402/baekjoon/blob/main/solution/backtracking/22944/main.py

#include <math.h>

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

const int MAX = 500;
const int INF = 1e9;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, h, d;
int startX, startY, endX, endY;
char board[MAX + 2][MAX + 2];
bool vis[MAX + 2][MAX + 2];
vector<pair<int, int>> umbs;
int ans = INF;

struct Node {
    int x;
    int y;
    int health;
    int durability;
    int dist;
};

void init();
void dfs(Node);
int minimumDist(int, int, int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    dfs({startX, startY, h, 0, 0});
    cout << (ans == INF ? -1 : ans) << endl;
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
            } else if (temp == 'E') {
                endX = i;
                endY = j;
            } else if (temp == 'U') {
                umbs.push_back({i, j});
            }

            board[i][j] = temp;
        }
    }
}

// cur = {x, y, health, durability, dist}
void dfs(Node cur) {
    int dist = minimumDist(cur.x, cur.y, endX, endY);
    // 끝까지 바로 갈 수 있으면
    if (dist <= cur.health + cur.durability) {
        // 그냥 바로 감(가장 빠름)
        ans = min(ans, dist + cur.dist);
        return;
    }

    // 우산의 조합에 따라 백트래킹 수행
    // S -> E
    // S -> U1 -> E
    // S -> U1 -> U2 -> E
    // ...
    for (auto umb : umbs) {
        if (vis[umb.X][umb.Y]) continue;
        int dist = minimumDist(umb.X, umb.Y, cur.x, cur.y);
        if (dist > cur.health + cur.durability) continue;
        vis[umb.X][umb.Y] = true;
        if (dist <= cur.durability) {
            dfs({umb.X, umb.Y, cur.health, d, dist + cur.dist});
        } else {
            dfs({umb.X, umb.Y, cur.health + cur.durability - dist, d, dist + cur.dist});
        }
        vis[umb.X][umb.Y] = false;
    }
}

int minimumDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
