#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;
#define endl '\n'

const int MAX = 1e6;

int n;
// input: 입력 배열
int input[MAX + 2];
// dp[i]: i번째 요소가 LIS에서 위치할 수 있는 인덱스
int dp[MAX + 2];

vector<int> lis;

int binarySearch(int, int, int);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	// 1. 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	dp[0] = 0;
	lis.push_back(input[0]);

	// 2. 최장공통 수열 찾기
	for (int i = 1; i < n; i++) {
		int last = lis[lis.size() - 1];
		if (last < input[i]) {
			lis.push_back(input[i]);
			dp[i] = lis.size() - 1;
			continue;
		}
		// 2-1. lower bound로 i번째 요소가 LIS의 위치(인덱스) 찾기
		int idx = binarySearch(0, lis.size() - 1, input[i]);
		lis[idx] = input[i];
		dp[i] = idx;
	}
	
	// 3. 결과 출력
	// lis배열을 "거꾸로" 추적하면서 res 스택에 넣음
	stack<int> res;
	int len = lis.size();
	// lastIdx: LIS의 마지막 인덱스 ( <=> LIS의 길이 - 1 )
	int lastIdx = len - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (lastIdx == -1) break;
		// dp[i](i번째 요소의 lis에서의 인덱스)를 거꾸로 순회하면서
		// lastIdx가 되는 값을 찾아나감
		// 이 둘이 같다는 의미: input[i]가 LISdml lastIdx 번째가 된다는 의미
		if (lastIdx == dp[i]) {
			res.push(input[i]);
			lastIdx--;
		}
	}

	cout << len << endl;
	while (!res.empty()) {
		cout << res.top() << ' ';
		res.pop();
	}
}

int binarySearch(int start, int end, int target) {
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (lis[mid] < target) {
			start = mid + 1;
			continue;
		}
		end = mid;
	}
	return start;
}