#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int MAX = 1e7;

int n;
vector<pair<int, int>> vec;
bool isPrime[MAX + 2];

void init();
void solve();
int gcd(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
}

void init() {
    cin >> n;
    fill(isPrime, isPrime + n + 1, true);
}

void solve() {
    if (n == 1) return;

    isPrime[1] = false;
    isPrime[2] = true;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    int temp = n;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        if (temp < i) break;
        int cnt = 0;
        while (temp % i == 0) {
            temp /= i;
            cnt++;
        }
        if (cnt == 0) continue;
        vec.push_back({i, cnt});
    }
    int len = vec.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < vec[i].second; j++) {
            cout << vec[i].first << endl;
        }
    }
}