#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 500;

int n, m;
vector<int> graph[MAX + 2];
int indegree[MAX + 2];
int cost[MAX + 2];
int res[MAX + 2];
queue<int> q;

void init();
void solve();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n;

	int temp;
	int check;
	for (int i = 1; i <= n; i++) {
		check = 0;
		while (true) {
			cin >> temp;
			if (temp == -1) break;
			if (check == 0) {
				check++;
				cost[i] = temp;
				res[i] = temp;
			}
			else {
				graph[temp].push_back(i);
				indegree[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
}

void solve() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			int target = graph[cur][i];
			res[target] = max(res[cur] + cost[target], res[target]);
			indegree[target]--;
			if (indegree[target] == 0) {
				q.push(target);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << endl;
	}
}