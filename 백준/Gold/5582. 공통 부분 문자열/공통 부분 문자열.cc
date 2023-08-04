#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

int n;
string str1, str2;
int dp[4002][4002];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str1 >> str2;
	int str1Len = str1.length();
	int str2Len = str2.length();

	int ans = 0;
	for (int i = 1; i <= str1Len; i++) {
		for (int j = 1; j <= str2Len; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;
}