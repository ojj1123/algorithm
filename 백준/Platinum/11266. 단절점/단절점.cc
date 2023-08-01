#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
#define endl '\n'

const int INF = 1e9;

int v, e;
int vis[10002];
vector<int> graph[10002];
bool isCut[10002];
int order;

void init();
void solve();
int dfs(int, bool);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> v >> e;
	int a, b;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

int dfs(int here, bool isRoot) {
	vis[here] = ++order;

	int ret = vis[here];
	int childCnt = 0;

	int size = graph[here].size();
	for (int i = 0; i < size; i++) {
		int next = graph[here][i];

		// 이미 방문한 정점이라면
		if (vis[next] != 0) {
			ret = min(ret, vis[next]);
			continue;
		}

		// 아직 방문하지 않은 정점이라면
		childCnt++;

		int lowOrder = dfs(next, false);

		// 루트 정점이 아니고 here 정점의 자식들 중 here 정점을 거치지 않고 
		// 갈 수 있는 노드의 방문번호가 작지 않다면(우회 경로가 없는 경우)
		if (!isRoot && lowOrder >= vis[here]) {
			isCut[here] = true;
		}
		ret = min(ret, lowOrder);
	}

	// 루트정점이면서 here 의 자식 트리 개수가 2 이상이면
	if (isRoot && childCnt >= 2) {
		isCut[here] = true;
	}

	return ret;
}

void solve() {
	// 연결 그래프가 아니므로 모든 정점을 순회할 필요가 있음
	for (int i = 1; i <= v; i++) {
		if (vis[i] != 0) continue;
		dfs(i, true);
	}

	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (!isCut[i]) continue;
		cnt++;
	}
	cout << cnt << endl;
	for (int i = 1; i <= v; i++) {
		if (!isCut[i]) continue;
		cout << i << ' ';
	}
}