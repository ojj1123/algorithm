#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define endl '\n'

const int MAX = 30;

int t;
int dp[MAX + 2][MAX + 2];

void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> t;
	solve();
	int n, m;
	while (t--) {
		cin >> n >> m;
		cout << dp[m][n] << endl;
	}
}

void solve() {
	for (int i = 1; i <= MAX; i++) dp[i][0] = dp[i][i] = 1;

	for (int i = 2; i <= MAX; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}
