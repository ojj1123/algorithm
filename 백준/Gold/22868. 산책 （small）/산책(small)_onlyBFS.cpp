// Reference : https://howudong.tistory.com/36

#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'
#define X first
#define Y second

const int MAX = 1e4;

int n, m, st, en;
int ans;
vector<int> graph[MAX + 2];
// i번째 정점을 방문하면서 지금까지 왔던 정점을 vis[i].second에 저장
pair<bool, vector<int>> vis[MAX + 2];

void init();
void solve();
void bfs(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> st >> en;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(st, en);
    int len = vis[en].second.size() - 1;
    ans += len;

    vector<int> endVec = vis[en].second;
    for (int i = 1; i <= n; i++) {
        vis[i].first = false;
        vis[i].second.clear();
    }

    for (int i = 0; i < endVec.size(); i++) {
        vis[endVec[i]].first = true;
    }
    vis[st].first = false;
    vis[en].first = false;

    bfs(en, st);
    len = vis[st].second.size() - 1;
    ans += len;
    cout << ans << endl;
}

void bfs(int s, int e) {
    queue<int> q;
    vis[s].first = true;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        vis[cur].second.push_back(cur);
        if (cur == e) break;
        q.pop();

        for (int next : graph[cur]) {
            if (vis[next].first) continue;
            vis[next].first = true;
            vis[next].second = vis[cur].second;
            q.push(next);
        }
    }
}
