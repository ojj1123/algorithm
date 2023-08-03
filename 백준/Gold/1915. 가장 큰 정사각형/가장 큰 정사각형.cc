#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &dp[i][j]);
			if (i > 0 && j > 0 && dp[i][j] != 0) dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans;
}