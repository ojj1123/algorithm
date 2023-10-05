#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int skillLen = skill.size();
    int n = board.size();
    int m = board[0].size();
    
    for(int i = 0;i < skillLen;i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = type == 1 ? -skill[i][5] : skill[i][5];
        dp[r1][c1] += degree;
        dp[r2 + 1][c2 + 1] += degree;
        dp[r1][c2 + 1] += -degree;
        dp[r2 + 1][c1] += -degree;
    }
    for(int i = 0;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    
    for(int i = 0;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            dp[j][i] += dp[j - 1][i];
        }
    }
    
    for(int i = 0; i < n;i++) {
        for(int j = 0;j < m;j++) {
            board[i][j] += dp[i][j];
            if(board[i][j] >= 1) answer++;
        }
    }
    return answer;
}