#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

void solve();
int gcd(int, int);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	solve();
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a * d) + (b * c);
	int B = (b * d);
	int g = gcd(A, B);
	cout << A / g << ' ' << B / g;
}
