#include <bits/stdc++.h>
using namespace std;

int n;
int minValue = 10e9;
int board[22][22];
bool selected[22];

void brute(int k, int cur) {
    if (k >= n / 2) {
        int startTotal = 0, linkTotal = 0;
        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = i + 1; j <= n; j++) {
                    if (selected[j]) {
                        startTotal += board[i][j] + board[j][i];
                    }
                }
            } else {
                for (int j = i + 1; j <= n; j++) {
                    if (!selected[j]) {
                        linkTotal += board[i][j] + board[j][i];
                    }
                }
            }
        }
        minValue = min(minValue, abs(startTotal - linkTotal));

        return;
    }
    for (int i = cur; i <= n; i++) {
        selected[i] = true;
        brute(k + 1, i + 1);
        selected[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    brute(0, 1);
    cout << minValue;
    return 0;
}