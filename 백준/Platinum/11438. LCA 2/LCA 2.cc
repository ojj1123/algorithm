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

const int MAX = 1e5;
int n, m, K;
vector<int> graph[MAX + 2];
queue<int> q;
int parent[17][MAX + 2];
int depth[MAX + 2];

void init();
void dfs(int, int);
void fillParent();
int lca(int, int);
void solve();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    dfs(1, 1);
    fillParent();
    solve();
}

void init() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < n; i <<= 1) {
        K++;
    }
}

void dfs(int here, int cnt) {
    depth[here] = cnt;

    for (int next : graph[here]) {
        if (depth[next] != 0) continue;
        parent[0][next] = here;
        dfs(next, cnt + 1);
    }
}

void fillParent() {
    for (int k = 1; k <= K; k++) {
        for (int v = 1; v <= n; v++) {
            parent[k][v] = parent[k - 1][parent[k - 1][v]];
        }
    }
}

int lca(int a, int b) {
    // a가 더 깊도록 조정
    if (depth[a] < depth[b]) swap(a, b);

    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= depth[a] - depth[b]) {
            a = parent[i][a];
        }
    }

    if (a == b) return a;

    for (int i = K; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

void solve() {
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
