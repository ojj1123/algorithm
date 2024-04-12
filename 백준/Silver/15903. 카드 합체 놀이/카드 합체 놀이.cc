#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void init();
void solve();

int main() {
    init();
    solve();
}

void init() {
    cin >> n >> m;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        pq.push(input);
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        ll sum = 0;
        for (int t = 0; t < 2; t++) {
            sum += pq.top();
            pq.pop();
        }
        pq.push(sum);
        pq.push(sum);
    }

    ll answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}