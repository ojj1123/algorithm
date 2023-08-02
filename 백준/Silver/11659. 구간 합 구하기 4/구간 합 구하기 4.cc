#include <iostream>
using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)


int main() {
	FAST;
	int n, m;
	
	cin >> n >> m;
	int *arr = new int[n + 1]{ 0, };
	int x;
	for (int i = 1; i < n+1; i++) {
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int first, last;
		cin >> first >> last;
		sum = arr[last] - arr[first - 1];
		cout << sum << "\n";
	}

	return 0;
}