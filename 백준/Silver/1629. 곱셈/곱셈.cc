#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using ll = long long;
ll POW(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll temp = POW(a, b / 2, c);
	temp = temp * temp%c;
	if (b % 2 == 0) return temp;
	return temp * a%c;
}

int main() {
	FAST;
	int a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
	return 0;
}