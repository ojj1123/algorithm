#include <bits/stdc++.h>
using namespace std;

int r, c, t, total;
int board[2][52][52];
vector<pair<int, int>> cleaner;
vector<pair<int, int>> cleanPath[2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int temp;
            cin >> temp;
            board[0][i][j] = board[1][i][j] = temp;
            if (temp == -1) {
                cleaner.push_back({i, j});
                continue;
            }
            total += temp;
        }
    }

    for (int i = 0; i < 2; i++) {
        int cx = cleaner[i].first;
        int cy = cleaner[i].second;
        if (i == 0) {
            if (cy == 0) {
                for (int j = cx - 1; j >= 0; j--) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({0, j});
                for (int j = 1; j <= cx; j++) cleanPath[i].push_back({j, c - 1});
                for (int j = c - 2; j > 0; j--) cleanPath[i].push_back({cx, j});
            } else if (cy == c - 1) {
                for (int j = cy - 1; j >= 0; j--) cleanPath[i].push_back({cx, j});
                for (int j = cx - 1; j >= 0; j--) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({0, j});
                for (int j = 1; j < cx; j++) cleanPath[i].push_back({j, c - 1});
            } else {
                for (int j = cy - 1; j >= 0; j--) cleanPath[i].push_back({cx, j});
                for (int j = cx - 1; j >= 0; j--) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({0, j});
                for (int j = 1; j <= cx; j++) cleanPath[i].push_back({j, c - 1});
                for (int j = c - 2; j > cy; j--) cleanPath[i].push_back({cx, j});
            }
        } else {
            if (cy == 0) {
                for (int j = cx + 1; j < r; j++) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({r - 1, j});
                for (int j = r - 2; j >= cx; j--) cleanPath[i].push_back({j, c - 1});
                for (int j = c - 2; j > 0; j--) cleanPath[i].push_back({cx, j});
            } else if (cy == c - 1) {
                for (int j = cy - 1; j >= 0; j--) cleanPath[i].push_back({cx, j});
                for (int j = cx + 1; j < r; j++) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({r - 1, j});
                for (int j = r - 2; j > cx; j--) cleanPath[i].push_back({j, c - 1});
            } else {
                for (int j = cy - 1; j >= 0; j--) cleanPath[i].push_back({cx, j});
                for (int j = cx + 1; j < r; j++) cleanPath[i].push_back({j, 0});
                for (int j = 1; j < c; j++) cleanPath[i].push_back({r - 1, j});
                for (int j = r - 2; j >= cx; j--) cleanPath[i].push_back({j, c - 1});
                for (int j = c - 2; j > cy; j--) cleanPath[i].push_back({cx, j});
            }
        }
    }

    for (int time = 0; time < t; time++) {
        int cur = time % 2;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int temp = board[cur][i][j];
                // -1 : 공기청정기 자리, 0 : 빈공간, 1 - 4 : 확산안됨
                if (temp < 5) {
                    continue;
                }
                int dust = temp / 5;

                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (board[cur][nx][ny] == -1) continue;
                    cnt++;
                    board[1 - cur][nx][ny] += dust;
                }
                board[1 - cur][i][j] -= cnt * dust;
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < cleanPath[i].size(); j++) {
                int curX = cleanPath[i][j].first;
                int curY = cleanPath[i][j].second;
                if (j == 0) {
                    total -= board[1 - cur][curX][curY];
                    continue;
                } else {
                    int prevX = cleanPath[i][j - 1].first;
                    int prevY = cleanPath[i][j - 1].second;
                    board[1 - cur][prevX][prevY] = board[1 - cur][curX][curY];
                    if (j == cleanPath[i].size() - 1) {
                        board[1 - cur][curX][curY] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[cur][i][j] = board[1 - cur][i][j];
            }
        }
    }

    cout << total;

    return 0;
}