#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;
#define endl '\n'

const int MAX = 4 * 1e6;

int n;
bool isPrime[MAX + 2];
vector<int> primeNum;

void init();
void solve();
void checkPrime();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	init();
	checkPrime();
	solve();
}

void init() {
	cin >> n;
	fill(isPrime, isPrime + n + 1, true);
}

void checkPrime() {
	isPrime[1] = false;
	isPrime[2] = true;
	
	for (int i = 2; i * i <= n; i++) {
		if (!isPrime[i]) continue;
        // i^2 부터 소거하는 것이 빠름
		for (int j = i * i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
}

void solve() {
	if (n == 1) {
		cout << 0;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (isPrime[i]) primeNum.push_back(i);
	}

	int left = 0;
	int right = 0;
	int sum = 0;
	int len = primeNum.size();
	int ans = isPrime[n] ? 1 : 0;

	while (true) {
		if (sum < n) {
			if (right == len - 1) break;
			sum += primeNum[right++];
		}
		else if (sum>=n) {
			sum -= primeNum[left++];
		}

		if (sum == n) ans++;
	}
	cout << ans;
}
