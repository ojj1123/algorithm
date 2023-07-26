#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
#define X first
#define Y second
#define endl '\n'

const int INF = 1e9;
const int MAX = 1e6;
int offset;
ll input[MAX + 1];
vector<ll> indexedTree;
int n, m, k;

void init();
void solve();
void update(int, ll);
ll sum(int, int);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> input[i];

	for (offset = 1; offset <= n; offset <<= 1);

	indexedTree.assign(2 * offset + 2, 0);
	for (int i = 0; i < n; i++) {
		indexedTree[i + offset] = input[i];
	}

	for (int i = offset - 1; i > 0; i--) {
		indexedTree[i] = indexedTree[2 * i] + indexedTree[2 * i + 1];
	}
}

void solve() {
	ll a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << sum(b - 1, c - 1) << endl;
		}
	}
}

void update(int pos, ll value) {
	int index = pos + offset;

	input[pos] = value;
	indexedTree[index] = value;
	while (index > 1) {
		index /= 2;
		indexedTree[index] = indexedTree[2 * index] + indexedTree[2 * index + 1];
	}
}

ll sum(int start, int end) {
	int left = offset + start;
	int right = offset + end;
	ll ret = 0;
	while (left <= right) {
		if (left % 2 == 1) ret += indexedTree[left++];
		if (right % 2 == 0) ret += indexedTree[right--];
		left /= 2;
		right /= 2;
	}
	return ret;
}