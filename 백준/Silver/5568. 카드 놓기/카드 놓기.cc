#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <set>
using namespace std;
#define endl '\n'

const int MAX = 1e8;

int n, k, ans;
string input[10];
vector<string> arr;
bool isUsed[10];
set<string> checkset;

void init();
void brute(int);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	brute(0);
	cout << checkset.size();
}

void init() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> input[i];
}

void brute(int cur) {
	if (cur >= k) {
		string str = "";
		for (int i = 0; i < k; i++) str += arr[i];
		checkset.insert(str);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isUsed[i]) continue;
		arr.push_back(input[i]);
		isUsed[i] = true;
		brute(cur + 1);
		isUsed[i] = false;
		arr.pop_back();
	}
}
