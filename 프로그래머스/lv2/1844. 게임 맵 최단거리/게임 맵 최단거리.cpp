#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int vis[102][102];

int solution(vector<vector<int>> maps) {
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0;i < n;i++) fill(vis[i], vis[i] + m + 1, -1);
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0) continue;
            if(vis[nx][ny] != -1) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    answer = vis[n - 1][m - 1];
    
    return answer;
}