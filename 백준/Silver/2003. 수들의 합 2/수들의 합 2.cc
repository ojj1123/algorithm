#include <iostream>

using namespace std;

int arr[10002];
int n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left, right, cnt, sum;
	left = 0;
	right = 0;
	cnt = 0;
	sum = 0;

	while (true) {
		if (sum < m) {
			if (right == n) break;
			sum += arr[right++];
		}
		else {
			sum -= arr[left++];
		}

		if (sum == m) cnt++;
	}
	cout << cnt;
}
