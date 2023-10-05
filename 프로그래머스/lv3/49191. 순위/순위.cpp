#include <string>
#include <vector>

using namespace std;

bool board[102][102];

void floydwarshall(int);

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0;i < results.size();i++) {
        int a = results[i][0];
        int b = results[i][1];
        board[a][b] = 1;
    }
    
    floydwarshall(n);
    
    for(int i = 1;i <= n;i++) {
        int cnt = 0;
        for(int j = 1;j <= n;j++) {
            if(board[i][j] || board[j][i]) cnt++;
        }
        if(cnt == n - 1) answer++;
    }
    return answer;
}

void floydwarshall(int n) {
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(board[i][k] && board[k][j]) board[i][j] = true;
            }
        }
    }
}