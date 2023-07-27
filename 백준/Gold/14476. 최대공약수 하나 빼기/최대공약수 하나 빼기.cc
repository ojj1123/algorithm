#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int MAX = 1e6;

int n, offset;
int arr[MAX + 1];
vector<int> indexedTree;

void init();
void makeIndexedTree();
void update(int, int);
int query(int, int);
void solve();
int gcd(int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    makeIndexedTree();
    solve();
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve() {
    bool flag = true;
    int g = -1;
    int k;
    for (int i = 0; i < n; i++) {
        // 뺄 숫자를 0으로 바꿈
        update(i, 0);
        int temp = query(0, n - 1);
        if (arr[i] % temp != 0) {
            if (g < temp) {
                flag = false;
                g = temp;
                k = arr[i];
            }
        }
        update(i, arr[i]);
    }
    if (flag)
        cout << -1;
    else
        cout << g << ' ' << k;
}

void makeIndexedTree() {
    for (offset = 1; offset < n; offset <<= 1)
        ;
    indexedTree.assign(2 * offset + 2, 0);

    for (int i = 0; i < n; i++) {
        indexedTree[i + offset] = arr[i];
    }

    for (int i = offset - 1; i > 0; i--) {
        indexedTree[i] = gcd(indexedTree[2 * i], indexedTree[2 * i + 1]);
    }
}

void update(int pos, int newValue) {
    int index = pos + offset;
    indexedTree[index] = newValue;
    while (index > 1) {
        index /= 2;
        indexedTree[index] = gcd(indexedTree[2 * index], indexedTree[2 * index + 1]);
    }
}

int query(int start, int end) {
    int left = start + offset;
    int right = end + offset;
    int ret = 0;
    while (left <= right) {
        if (left % 2 == 1) ret = gcd(ret, indexedTree[left++]);
        if (right % 2 == 0) ret = gcd(ret, indexedTree[right--]);
        left /= 2;
        right /= 2;
    }
    return ret;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}