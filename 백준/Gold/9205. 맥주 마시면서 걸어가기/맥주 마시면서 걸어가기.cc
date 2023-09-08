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

int t, n;
pair<int, int> coord[105];
vector<int> graph[105];
bool vis[105];

void init();
int getDist(int, int, int, int);
int bfs();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--) {
        init();
        int res = bfs();

        if (res == 1) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }
}

void init() {
    cin >> n;
    int last = n + 2;
    for (int i = 0; i < last; i++) {
        cin >> coord[i].X >> coord[i].Y;
    }

    for (int i = 0; i < last; i++) {
        graph[i].clear();
    }

    for (int i = 0; i < last - 1; i++) {
        for (int j = i + 1; j < last; j++) {
            int dist = getDist(coord[i].X, coord[i].Y, coord[j].X, coord[j].Y);
            if (dist > 1000) continue;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }

    fill(vis, vis + last, false);
}

int bfs() {
    queue<int> q;

    vis[0] = true;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n + 1) return 1;

        for (int next : graph[cur]) {
            if (vis[next]) continue;
            vis[next] = true;
            q.push(next);
        }
    }

    return -1;
}

int getDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}