#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 2 * 1e5;

int parent[MAX + 5];
int ranking[MAX + 5];
int personCnt[MAX + 5];

int t, f;
string name1, name2;
map<string, int> nameMap;

int find(int);
void merge(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;

    int cnt;
    while (t--) {
        cin >> f;
        cnt = 0;
        nameMap.clear();
        for (int i = 0; i < 2 * f; i++) {
            parent[i] = i;
        }
        fill(ranking, ranking + (2 * f), 0);
        fill(personCnt, personCnt + (2 * f), 1);

        for (int i = 0; i < f; i++) {
            cin >> name1 >> name2;
            if (nameMap.find(name1) == nameMap.end()) {
                nameMap.insert({name1, cnt});
                cnt++;
            }
            if (nameMap.find(name2) == nameMap.end()) {
                nameMap.insert({name2, cnt});
                cnt++;
            }
            int a = nameMap[name1];
            int b = nameMap[name2];

            merge(a, b);
        }
    }
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        cout << personCnt[u] << endl;
        return;
    }
    if (ranking[u] < ranking[v]) swap(u, v);
    parent[v] = u;
    personCnt[u] += personCnt[v];
    cout << personCnt[u] << endl;

    if (ranking[u] == ranking[v]) ranking[u]++;
}