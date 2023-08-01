#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
#define endl '\n'

const int INF = 1e9;

int n, m;
ll dist[502];
int edgeList[6002][3];
bool isUpdateFlag = false;

void init();
void bellmanFord();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	bellmanFord();
	if (isUpdateFlag) {
		cout << -1 << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			cout << (dist[i] == INF ? -1 : dist[i]) << endl;
		}
	}

}

void init() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> edgeList[i][j];
		}
	}
}

void bellmanFord() {
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int start = edgeList[j][0];
			int end = edgeList[j][1];
			int time = edgeList[j][2];

			if (dist[start] >= INF) continue;

			dist[end] = min(dist[end], dist[start] + time);
		}
	}

	for (int j = 0; j < m; j++) {
		int start = edgeList[j][0];
		int end = edgeList[j][1];
		int time = edgeList[j][2];

		if (dist[start] >= INF) continue;

		if (dist[end] > dist[start] + time) {
			isUpdateFlag = true;
			return;
		}
	}
}