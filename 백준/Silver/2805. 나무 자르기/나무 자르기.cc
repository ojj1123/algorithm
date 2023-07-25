#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int INF = 10e9;
const int MAX = 10e6;

int arr[MAX];
int n, m, maxTree;

void init();
int binarySearch(int, int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cout << binarySearch(0, maxTree, m);
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxTree = max(arr[i], maxTree);
    }
}

bool check(int currentLength) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (currentLength >= arr[i]) continue;
        sum += arr[i] - currentLength;
    }
    return sum >= m;
}
int binarySearch(int start, int end, int target) {
    if (start > end) return end;

    int mid = (start + end) / 2;
    if (check(mid)) return binarySearch(mid + 1, end, target);
    return binarySearch(start, mid - 1, target);
}