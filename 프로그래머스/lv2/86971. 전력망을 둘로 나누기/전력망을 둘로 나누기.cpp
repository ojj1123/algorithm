#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 1e9;
bool vis[102];
vector<int> tree[102];
int ret;

int dfs(int start, int no) {
    vis[start] = true;
    
    for(int next: tree[start]) {
        if(vis[next]) continue;
        if(next == no) continue;
        dfs(next, no);
        ret++;
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    for(int i = 0;i < n - 1;i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    for(int i = 0;i < n - 1;i++) {
        fill(vis, vis + n + 1, false);
        
        int a = wires[i][0];
        int b = wires[i][1];
        
        ret = 1;
        int cnt1 = dfs(a, b);
        ret = 1;
        int cnt2 = dfs(b, a);
        
        answer = min(answer, abs(cnt1 - cnt2));
    }
    
    return answer;
}