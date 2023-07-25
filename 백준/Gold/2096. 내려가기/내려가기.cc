#include <iostream>
#include <algorithm>

using namespace std;

int n;
int maxVal[3], minVal[3];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
    int input[3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> input[j];

		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				maxVal[j] = minVal[j] = input[j];
			}
		} else {
			int maxTmp[3], minTmp[3];
			maxTmp[0] = max(maxVal[0], maxVal[1]) + input[0];
			minTmp[0] = min(minVal[0], minVal[1]) + input[0];
		
			maxTmp[1] = max(max(maxVal[0], maxVal[1]), maxVal[2]) + input[1];
			minTmp[1] = min(min(minVal[0], minVal[1]), minVal[2]) + input[1];
		
			maxTmp[2] = max(maxVal[1], maxVal[2]) + input[2];
			minTmp[2] = min(minVal[1], minVal[2]) + input[2];
			for (int j = 0; j < 3; j++) {
				maxVal[j] = maxTmp[j];
				minVal[j] = minTmp[j];
			}
		}
	}

	int maxAns = max(max(maxVal[0], maxVal[1]), maxVal[2]);
	int minAns = min(min(minVal[0], minVal[1]), minVal[2]);

	cout << maxAns << ' ' << minAns;
}