// Backtracking 풀이

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

int N, M, totalCost;
int m[105];
int c[105];
int dp[10005][105];

void init();
void solve();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> m[i];
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        totalCost += c[i];
    }
}

void solve() {
    for (int i = 1; i <= totalCost; i++) {
        for (int j = 1; j <= N; j++) {
            if (i < c[j]) {
                // 한계 비용 < 넣고자 하는 앱의 비용
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = max(dp[i - c[j]][j - 1] + m[j], dp[i][j - 1]);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= totalCost; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] >= M) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
}