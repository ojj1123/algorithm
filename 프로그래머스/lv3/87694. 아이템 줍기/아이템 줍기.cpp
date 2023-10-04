#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int board[105][105];
int vis[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void drawBoard(vector<vector<int>>);
void bfs(int, int, int, int);

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i = 0;i < rectangle.size();i++) {
        rectangle[i][0] *= 2;
        rectangle[i][1] *= 2;
        rectangle[i][2] *= 2;
        rectangle[i][3] *= 2;
    }
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i = 0;i <= 102;i++) {
        fill(board[i], board[i] + 103, -1);
    }
    
    drawBoard(rectangle);
    
    bfs(characterX, characterY, itemX, itemY);
    
    answer = (vis[itemX][itemY] - 1) / 2;
    
    return answer;
}

void drawBoard(vector<vector<int>> rectangle) {
    for(int i = 0;i < rectangle.size();i++) {
        int lx = rectangle[i][0];
        int ly = rectangle[i][1];
        int rx = rectangle[i][2];
        int ry = rectangle[i][3];
        
        for(int x = lx;x <= rx;x++) {
            if(board[x][ly] == -1) board[x][ly] = 1;
            if(board[x][ry] == -1) board[x][ry] = 1;
        }
        for(int y = ly;y <= ry;y++) {
            if(board[lx][y] == -1) board[lx][y] = 1;
            if(board[rx][y] == -1) board[rx][y] = 1;
        }
        for(int x = lx + 1;x <= rx - 1;x++) {
            for(int y = ly + 1;y <= ry - 1;y++) {
                if(board[x][y] != 0) board[x][y] = 0;
            }
        }
    }
}

void bfs(int characterX, int characterY, int itemX, int itemY) {
    queue<pair<int, int>> q;
    vis[characterX][characterY] = 1;
    q.push({characterX, characterY});
    
    while(!q.empty()) {
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        
        q.pop();

        if(cx == itemX && cy == itemY) break;
        
        for(int dir = 0; dir < 4;dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(board[nx][ny] != 1) continue;
            if(vis[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}