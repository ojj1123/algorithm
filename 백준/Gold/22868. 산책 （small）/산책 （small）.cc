#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 1e4;

int n, m, st, en;
vector<int> graph[MAX + 2];
int vis[MAX + 2];
bool vis2[MAX + 2];
bool isFirstVisited[MAX + 2];

void init();
void solve();
bool dfs(int);

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

    fill(vis, vis + n + 2, -1);

    int ans = 0;
    queue<pair<int, int>> q;
    vis[st] = 0;
    q.push({0, st});

    bool flag = false;

    while (!q.empty()) {
        auto item = q.front();
        q.pop();
        int prev = item.first;
        int cur = item.second;

        for (int next : graph[cur]) {
            if (vis[next] != -1) continue;
            vis[next] = vis[cur] + 1;
            if (next == en) {
                flag = true;
                break;
            }
            q.push({cur, next});
        }
        if (flag) break;
    }

    ans += vis[en];
    // 최초 경로 찾기
    dfs(st);
    isFirstVisited[st] = false;

    // en -> st bfs
    fill(vis, vis + n + 2, -1);
    queue<int> q2;
    vis[en] = 0;
    q2.push(en);
    flag = false;
    while (!q2.empty()) {
        int cur = q2.front();
        q2.pop();

        for (int next : graph[cur]) {
            if (isFirstVisited[next]) continue;
            if (vis[next] != -1) continue;
            vis[next] = vis[cur] + 1;
            if (next == st) {
                flag = true;
                break;
            }
            q2.push(next);
        }
        if (flag) break;
    }
    ans += vis[st];
    cout << ans << endl;
}

bool dfs(int cur) {
    vis2[cur] = true;

    for (int next : graph[cur]) {
        if (vis2[next]) continue;
        if (vis[next] == -1) continue;
        if (vis[next] < vis[cur] + 1) continue;

        if (next == en) {
            return true;
        }
        if (vis[next] == vis[cur] + 1) {
            bool flag = dfs(next);
            if (flag) {
                isFirstVisited[next] = true;
                return true;
            }
        }
    }
    return false;
}