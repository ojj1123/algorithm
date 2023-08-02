#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
#define endl '\n'

const int MAX = 1024;

int n, m;
int acc[MAX + 2][MAX + 2];

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n >> m;
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			acc[i][j] = acc[i][j - 1] + acc[i - 1][j] - acc[i - 1][j - 1] + temp;
		}
	}
}

void solve() {
	int x1, y1, x2, y2;
	int sum;
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		sum = acc[x2][y2] - acc[x2][y1 - 1] - acc[x1 - 1][y2] + acc[x1 - 1][y1 - 1];
		cout << sum << endl;
	}
}