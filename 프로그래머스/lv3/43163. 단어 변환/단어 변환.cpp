#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[55];
int vis[55];

bool canConnected(string a, string b, int len) {
    int diff = 0;
    
    for(int i = 0;i < len;i++) {
        if(a[i] != b[i]) diff++;    
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // target이 없는 경우
    int wordsLen = words.size();
    int targetPos = -1;
    for(int i = 0;i < wordsLen;i++) {
        if(target.compare(words[i]) == 0) targetPos = i;
    }
    if(targetPos == -1) return 0;
    
    
    // target이 있는 경우
    
    words.push_back(begin);
    int n = words.size();
    int len = begin.length();
    
    for(int i = 0;i < n - 1;i++) {
        for(int j = i + 1;j < n;j++) {
            if(canConnected(words[i], words[j], len)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    fill(vis, vis + n + 1, -1);
    queue<int> q;
    
    for(int i = 0;i < n;i++) {
        if(begin.compare(words[i]) != 0) continue;
        
        // begin과 같은 것
        q.push(i);
        vis[i] = 0;
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == targetPos) return vis[cur];
        for(int next: graph[cur]) {
            if(vis[next] != -1) continue;
            
            vis[next] = vis[cur] + 1;
            q.push(next);
        }
    }
    
    
    return vis[targetPos];
}