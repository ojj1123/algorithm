#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int dp[102][102];
bool check[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); i++) {
        check[puddles[i][1]][puddles[i][0]] = true;
    }
    
    for(int i = 2; i <= m; i++) {
        if(check[1][i]) break;
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        if(check[i][1]) break;
        dp[i][1] = 1;
    }
    
    for(int row = 2; row <= n; row++) {
        for(int col = 2; col <= m; col++) {
            if(check[row][col]) continue;
            dp[row][col] = ((dp[row - 1][col] % MOD) + (dp[row][col - 1]) % MOD) % MOD;
        }
    }
    return dp[n][m];
}