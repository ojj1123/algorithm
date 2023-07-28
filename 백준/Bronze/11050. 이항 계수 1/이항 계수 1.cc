#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int n, k;

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n >> k;
}

void solve() {
	int a = 1, b = 1, c = 1;
	for (int i = 1; i <= n; i++) {
		a *= i;
	}
	for (int i = 1; i <= k; i++) {
		b *= i;
	}
	for (int i = 1; i <= n-k; i++) {
		c *= i;
	}

	cout << a / (b * c);
}
