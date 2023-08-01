#include<bits/stdc++.h>
using namespace std;
#define INF 10000005
int n, m;
int board[102][102];
int dp[102][102];
void init() {
    cin>>n>>m;
    while(m--) {
        int a, b, c;
        cin>>a>>b>>c;
        if(board[a][b] == 0)
            board[a][b]=c;
        else if(board[a][b] > c) board[a][b]=c;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i == j) board[i][j] = 0;
            else if(board[i][j] == 0) board[i][j]=INF;
            dp[i][j]=board[i][j];
        }
    }
}
void floydWarshall() {
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j || j==k || i==k) continue;
                else if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j]=dp[i][k] + dp[k][j];
            }
        }
    }
}
void output() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dp[i][j]==0 || dp[i][j]>=INF) cout<<0;
            else cout<<dp[i][j];
            cout<<' ';
        }
        cout<<'\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    floydWarshall();
    output();
}