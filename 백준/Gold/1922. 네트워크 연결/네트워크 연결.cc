#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 1e3;

int arr[MAX + 2];
int parent[MAX + 2];
int ranking[MAX + 2];
int n, m;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> graph;

void init();
int kruskal();
int find(int u);
void merge(int u, int v);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	cout << kruskal();
}

void init() {
	cin >> n >> m;
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph.push({ c, {a, b} });
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

int kruskal() {
	int edgeCnt = 0;
	int minCost = 0;

	while (!graph.empty()) {
		if (edgeCnt == n - 1) break;
		auto cur = graph.top();
		graph.pop();

		int a = cur.second.first;
		int b = cur.second.second;
		int c = cur.first;

		// 이미 간선으로 선택된 경우 <==> 이미 a, b 사이의 최소 비용인 간선을 선택한 경우
		if (find(a) == find(b)) {
			continue;
		}
		merge(a, b);
		edgeCnt++;
		minCost += c;
	}
	return minCost;
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