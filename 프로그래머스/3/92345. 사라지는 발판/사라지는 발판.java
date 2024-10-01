import java.util.*;

class Solution {
    int[][] map;
    boolean[][] vis;
    int n, m;
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        int answer = -1;
        n = board.length;
        m = board[0].length;
        map = board;
        vis = new boolean[n][m];
        
        answer = dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
        
        return answer;
    }
    
    // 최선의 플레이를 했을 때의 턴 수
    public int dfs(int x1, int y1, int x2, int y2) {
        int ret = 0;
        
        // 이미 방문한 곳이라면
        if(vis[x1][y1]) return 0;
        
        for(int dir = 0;dir < 4;dir++) {
            int nx = x1 + dx[dir];
            int ny = y1 + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0) continue;
            if(vis[nx][ny]) continue;
            
            vis[x1][y1] = true;
            int turn = dfs(x2, y2, nx, ny) + 1;
            vis[x1][y1] = false;
            
            // 지금까지 졌는데 현재 분기에서도 지닌 경우 -> 가장 오래 끄는 턴수 선택
            if(ret % 2 == 0 && turn % 2 == 0) ret = Math.max(ret, turn);
            // 지금까지 졌는데, 현재에서 이긴 경우 -> 이긴 턴수 선택
            else if(ret % 2 == 0 && turn % 2 == 1) ret = turn;
            // 지금까지 이겼는데, 현재에서 이긴 경우 -> 가장 짧은 턴 수
            else if(ret % 2 == 1 && turn % 2 == 1) ret = Math.min(ret, turn);
        }
        
        return ret;
    }

}