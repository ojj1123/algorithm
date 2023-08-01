#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int V, E, K;
int u, v, w; // u->v w
vector<pair<int, int>> graph[20005];
int d[20005];
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; // 비용, 정점
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	fill(d, d + 20005, INF);
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}