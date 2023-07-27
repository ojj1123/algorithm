#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

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
}

void solve() {
    if (n == 1) return;

    int temp = n;
    for (int i = 2; i <= n; i++) {
        while (temp % i == 0) {
            cout << i << endl;
            temp /= i;
        }
    }
}