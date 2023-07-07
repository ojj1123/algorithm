#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m, r;
int board[302][302];

void rotate() {
    int check = min(n, m) / 2;
    for (int cnt = 0; cnt < check; cnt++) {
        int max_m = m - 1 - cnt;
        int max_n = n - 1 - cnt;
        int temp = board[cnt][cnt];
        // 위쪽 변
        for (int i = cnt; i < max_m; i++) board[cnt][i] = board[cnt][i + 1];
        // 오른쪽 변
        for (int i = cnt; i < max_n; i++) board[i][max_m] = board[i + 1][max_m];
        // 아래쪽 변
        for (int i = max_m; i > cnt; i--) board[max_n][i] = board[max_n][i - 1];
        // 왼쪽 변
        for (int i = max_n; i > cnt; i--) board[i][cnt] = board[i - 1][cnt];
        board[cnt + 1][cnt] = temp;
    }
}
int main() {
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < r; i++) rotate();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}