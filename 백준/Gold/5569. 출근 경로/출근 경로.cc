#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 100000;

int w, h;
/*
NOTE
dp[i][j][dir] : (i, j)로 올 때 dir 방향으로 온 경우의 수
dir == 0 : (➡ + ➡)방향으로 온 경우
dir == 1 : (➡ + ⬆)방향으로 온 경우
dir == 2 : (⬆ + ➡)방향으로 온 경우
dir == 3 : (⬆ + ⬆)방향으로 온 경우
*/
int dp[102][102][4];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> w >> h;

	for (int i = 1; i <= h; i++) {
		dp[i][1][3] = 1;
	}
	for (int i = 1; i <= w; i++) {
		dp[1][i][0] = 1;
	}

	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][2]) % MOD;
			dp[i][j][1] = dp[i - 1][j][0];
			dp[i][j][2] = dp[i][j - 1][3];
			dp[i][j][3] = (dp[i - 1][j][1] + dp[i - 1][j][3]) % MOD;
		}
	}
	int ans = 0;
	for (int dir = 0; dir < 4; dir++) ans = (ans + dp[h][w][dir]) % MOD;
	cout << ans;
}