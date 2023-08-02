#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define endl '\n'

int n;
int board[502][502];
int dp[502][502];

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> board[i][j];
		}
	}
}

void solve() {
	dp[1][1] = board[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + board[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + board[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + board[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}