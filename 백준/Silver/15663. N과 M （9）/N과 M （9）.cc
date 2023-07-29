#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl '\n'

const int INF = 1e9;
const int MAX = 1e7;

int n, m;
int input[10];
string strInput[10];
bool isUsed[10];
vector<string> arr;
set<string> check;
vector<string> output;

void init();
void solve(int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve(0);
    for (auto it = output.begin(); it != output.end(); it++) cout << *it << endl;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> input[i];
    sort(input, input + n);
    for (int i = 0; i < n; i++) strInput[i] = to_string(input[i]);
}

void solve(int cur) {
    if (cur >= m) {
        string str = "";
        for (int i = 0; i < m; i++) {
            str += arr[i] + ((i != m - 1) ? " " : "");
        }
        if (check.count(str) == 0) {
            check.insert(str);
            output.push_back(str);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isUsed[i]) continue;
        isUsed[i] = true;
        arr.push_back(strInput[i]);
        solve(cur + 1);
        isUsed[i] = false;
        arr.pop_back();
    }
}