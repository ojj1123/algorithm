#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1000000000;
ll x, y, z;

void init();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> x >> y;
	z = (y * 100) / x;

	if (x == y) {
		cout << -1;
		return 0;
	}

	int start = 1;
	int end = INF;
	int ans = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		long long tempZ = (y + mid) * 100 / (x + mid);

		if (z < tempZ) {
			end = mid - 1;
			ans = mid;
		} else {
			start = mid + 1;
		}
	}
	cout << ans;
}