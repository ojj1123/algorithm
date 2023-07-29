#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int n, m;
int input[10];
bool isUsed[10];
int check[10];

void init();
void solve(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve(0, 0);
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> input[i];
    sort(input, input + n);
}

void solve(int cnt, int cur) {
    if (cnt >= m) {
        for (int i = 0; i < m; i++) {
            cout << input[check[i]] << ' ';
        }
        cout << endl;
        return;
    }
    int temp = -1;
    for (int i = cur; i < n; i++) {
        if (isUsed[i] || input[i] == temp) continue;
        check[cnt] = i;
        temp = input[check[cnt]];
        isUsed[i] = true;
        solve(cnt + 1, i + 1);
        isUsed[i] = false;
    }
}