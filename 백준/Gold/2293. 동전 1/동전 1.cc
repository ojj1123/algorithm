#include <algorithm>
#include <iostream>

using namespace std;
#define endl '\n'

int N, K;
int value[102];
int dp[10002];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> value[i];
    }
    sort(value, value + N + 1);

    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= K; k++) {
            if (k == value[n]) {
                dp[k] += 1;
            } else if (k > value[n]) {
                dp[k] = dp[k] + dp[k - value[n]];
            }
        }
    }

    cout << dp[K] << endl;
}