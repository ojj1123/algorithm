#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'

const int VMAX = 1e5;
const int EMAX = 1e6;

int v, e;
vector<int> graph[VMAX + 2];
pair<int, int> edgeList[EMAX + 2];
int vis[EMAX + 2];
bool isCut[EMAX + 2];
int order;
vector<pair<int, int>> res;

void init();
int dfs(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    for (int i = 1; i <= v; i++) {
        if (vis[i] != 0) continue;
        dfs(i, 0);
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (auto it : res) {
        cout << it.first << ' ' << it.second << endl;
    }
}

void init() {
    cin >> v >> e;
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (a > b) {
            edgeList[i] = {a, b};
        } else {
            edgeList[i] = {b, a};
        }
    }
}

int dfs(int here, int parent) {
    vis[here] = ++order;

    int ret = vis[here];
    int childCnt = 0;

    int size = graph[here].size();
    for (int i = 0; i < size; i++) {
        int next = graph[here][i];

        if (next == parent) continue;
        // 이미 방문한 경우
        if (vis[next] != 0) {
            ret = min(ret, vis[next]);
            continue;
        }
        // 처음 방문한 경우
        int lowOrder = dfs(next, here);
        if (lowOrder > vis[here]) {
            res.push_back({min(here, next), max(here, next)});
        }
        ret = min(ret, lowOrder);
    }
    return ret;
}