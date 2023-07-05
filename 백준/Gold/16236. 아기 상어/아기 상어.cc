#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int board[22][22];
int dist[22][22];  // 아기상어 ~ 물고기 거리

int sharkSize = 2;
pair<int, int> sharkPos;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sharkPos = {i, j};
                board[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int eatCnt = 0;
    while (1) {
        // 상어 크기 비교
        if (sharkSize <= eatCnt) {
            sharkSize++;
            eatCnt = 0;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for (int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n, -1);

        queue<pair<int, int>> q;
        q.push(sharkPos);
        dist[sharkPos.X][sharkPos.Y] = 0;

        // 거리 계산(bfs)
        while (!q.empty()) {
            auto cur = q.front();  // 현재 위치
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != -1 || board[nx][ny] > sharkSize) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
                if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
                    pq.push({dist[nx][ny], nx, ny});  // { 거리, x, y } 오름차순(min-heap)
                }
            }
        }
        // 먹을 물고기가 없다면
        if (pq.empty()) break;

        // 먹기
        auto fish = pq.top();
        int d = get<0>(fish);
        int x = get<1>(fish);
        int y = get<2>(fish);
        board[x][y] = 0;  // 먹으면 빈칸됨
        eatCnt++;
        sharkPos = {x, y};
        ans += d;
    }

    cout << ans;
    return 0;
}