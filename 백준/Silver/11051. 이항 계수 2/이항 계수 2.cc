#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MOD = 10007;
int n, k;
int dp[1001];
int solve(int num) {
    if (num == 0 || num == 1) return 1;
    int &ret = dp[num];
    if (ret != -1) return ret;
    return ret = (num * solve(num - 1)) % MOD;
}
int POW(int a, int m) {
    int ret = 1;
    for (int i = 0; i < m; i++) {
        ret *= a;
        ret %= MOD;
    }
    return ret % MOD;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    fill(dp, dp + 1001, -1);
    dp[0] = 1;
    // int B = (dp[k] * dp[n - k] + MOD) % MOD;
    int C = (solve(k) * solve(n - k)) % MOD;
    cout << (solve(n) * POW(C, MOD - 2)) % MOD;
    return 0;
}