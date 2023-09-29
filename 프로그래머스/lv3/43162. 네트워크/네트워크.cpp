#include <string>
#include <vector>

using namespace std;

bool vis[202];
vector<vector<int>> board;

void dfs(int n, int start) {
    vis[start] = true;
    
    for(int next = 0;next < n;next++) {
        if(vis[next]) continue;
        if(board[start][next] == 0) continue;
        dfs(n, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    board = computers;
    for(int start = 0;start < n;start++) {
        if(vis[start]) continue;
        answer++;
        dfs(n, start);
    }
    return answer;
}