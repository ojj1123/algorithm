#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int INF = 10e9;
const int MAX = 4000;

int a[MAX], b[MAX], c[MAX], d[MAX];
int ab[MAX * MAX], cd[MAX * MAX];
int n;

void init();
void solve();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[n * i + j] = a[i] + b[j];
            cd[n * i + j] = c[i] + d[j];
        }
    }
    sort(ab, ab + n * n);
    sort(cd, cd + n * n);
}

void solve() {
    ll ans = 0;
    for (int i = 0; i < n * n; i++) {
        int len = upper_bound(cd, cd + n * n, -ab[i]) - lower_bound(cd, cd + n * n, -ab[i]);
        ans += len;
    }
    cout << ans;
}