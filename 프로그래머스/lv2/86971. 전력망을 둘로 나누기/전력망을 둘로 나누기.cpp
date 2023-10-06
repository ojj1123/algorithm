#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int siz[102];
vector<int> tree[102];

void dfs(int start, int prev) {
    siz[start] = 1;
    
    for(int next: tree[start]) {
        if(next == prev) continue;
        dfs(next, start);
        siz[start] += siz[next];
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    for(int i = 0;i < n - 1;i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, -1);
    
    for(int i = 1;i <= n;i++) {
        for(int j: tree[i]) {
            int left = siz[j];
            int right = n - siz[j];
            answer = min(answer, abs(left - right));
        }
    }
    
    return answer;
}