#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
#define endl '\n'

const int INF = 1 << 31 - 1;

int n;
int arr[502][2];
int dp[502][502];

int multiply(int, int);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + n + 1, -1);
	}

	cout << multiply(0, n - 1);
}

int multiply(int start, int end) {
	if (start == end) return 0;
	int ret = dp[start][end];
	if (ret != -1) return ret;

	int temp = INF;
	for (int i = start; i < end; i++) {
		temp = min(temp, multiply(start, i) + multiply(i + 1, end) + arr[start][0] * arr[i][1] * arr[end][1]);
	}

	return dp[start][end] = temp;
}