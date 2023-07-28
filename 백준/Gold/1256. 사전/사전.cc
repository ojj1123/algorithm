#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <set>
using namespace std;
#define endl '\n'

const int MAX = 1e9;

int n, m, k;
int cnt[102][102];

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n >> m >> k;
}

void solve() {

	for (int i = 0; i <= n; i++) {
		cnt[i][0] = 1;
	}
	for (int j = 0; j <= m; j++) {
		cnt[0][j] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
			// MAX를 넘는 경우 예외 처리
			if (cnt[i][j] >= MAX) {
				cnt[i][j] = MAX;
			}
		}
	}
	if (cnt[n][m] < k) {
		cout << -1;
		return;
	}

	int aCnt = n;
	int zCnt = m;
	int tempK = k;
	int totalLength = n + m;
	string res = "";

	while (true) {
		if (res.length() == totalLength) break;
		if (aCnt == 0 && zCnt == 0) break;
		if (aCnt == 0) {
			while (zCnt--) res += "z";
			continue;
		}
		if (zCnt == 0) {
			while (aCnt--) res += "a";
			continue;
		}
		
		int aFirst = cnt[aCnt - 1][zCnt];
		
		if (aFirst >= tempK) {
			res += "a";
			aCnt--;
			continue;
		}
		res += "z";
		zCnt--;
		tempK -= aFirst;
	}
	cout << res;
}
