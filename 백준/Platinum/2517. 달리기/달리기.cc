#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define endl '\n'

const int MAX = 5 * 1e5;

int n, offset;
pair<int, int> arr[MAX + 2];
vector<int> indexedTree;
int ans[MAX + 2];

void init();
void solve();
void update(int, int);
int sum(int, int);
bool compare(const pair<int, int> &, const pair<int, int> &);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	solve();
}

void init() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
		arr[i].first = i;
	}
}

void solve() {
	sort(arr, arr + n, compare);

	for (offset = 1; offset < n; offset <<= 1);
	indexedTree.assign(2 * offset + 2, 0);

	for (int i = 0; i < n; i++) {
		update(arr[i].first, 1);
		ans[arr[i].first] = sum(0, arr[i].first);
	}
	
	for (int i = 0; i < n; i++) cout << ans[i] << endl;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}

void update(int pos, int newValue) {
	int index = offset + pos;

	indexedTree[index] = newValue;
	while (index > 1) {
		index /= 2;
		indexedTree[index] = indexedTree[2 * index] + indexedTree[2 * index + 1];
	}
}

int sum(int start, int end) {
	int left = offset + start;
	int right = offset + end;
	int ret = 0;

	while (left <= right) {
		if (left % 2 == 1) ret += indexedTree[left++];
		if (right % 2 == 0) ret += indexedTree[right--];
		left /= 2;
		right /= 2;
	}
	return ret;
}