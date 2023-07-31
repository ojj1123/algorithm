#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 32000;

int n, m;
vector<int> graph[MAX + 2];
int indegree[MAX + 2];
queue<int> q;

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n >> m;

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
}

void solve() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		cout << cur << ' ';

		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			int target = graph[cur][i];
			indegree[target]--;
			if (indegree[target] == 0) q.push(target);
		}
	}
}