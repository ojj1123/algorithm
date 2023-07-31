#include <iostream>
using namespace std;
#define endl '\n'

const int MAX = 1e6;

int arr[MAX + 2];
int parent[MAX + 2];
int ranking[MAX + 2];
int n, m;

void init();
void solve();
int find(int u);
void merge(int u, int v);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	solve();
}

void init() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

void solve() {
	int k, a, b;
	while (m--) {
		cin >> k >> a >> b;
		if (k == 0) {
			merge(a, b);
		}
		else if (k == 1) {
			cout << (find(a) == find(b) ? "YES" : "NO") << endl;
		}
	}
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (ranking[u] < ranking[v]) swap(u, v);
	parent[v] = u;
	if (ranking[u] == ranking[v]) ranking[u]++;
}