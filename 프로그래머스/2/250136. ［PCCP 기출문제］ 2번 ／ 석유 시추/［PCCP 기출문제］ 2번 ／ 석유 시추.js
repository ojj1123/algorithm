const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function solution(land) {
    const n = land.length;
    const m = land[0].length;
    
    const columnMap = new Map();
    const sizeArr = [];
    
    const vis = Array.from(Array(n), () => Array.from(Array(m), () => false));
    
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            if(vis[i][j]) continue;
            if(land[i][j] === 0) continue;
            
            let size = 0;
            let num = sizeArr.length;
            const q = [];
            q.push({r: i, c: j});
            vis[i][j] = true;
            
            while(q.length !== 0) {
                const { r, c } = q.shift();
                
                columnMap.set(c, (columnMap.get(c) || new Set()).add(num));
                size++;
                
                for(let dir = 0;dir < 4;dir++) {
                    const nx = r + dx[dir];
                    const ny = c + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(land[nx][ny] === 0) continue;
                    if(vis[nx][ny]) continue;
                    
                    vis[nx][ny] = true;
                    q.push({r: nx, c: ny});
                }
            }
            sizeArr.push(size);
        }
    }
    
    let answer = 0;
    for(const columnSet of columnMap.values()) {
        let sum = 0;
        for(const column of columnSet.keys()) {
            sum += sizeArr[column];
        }
        answer = Math.max(answer, sum);
    }
    
    return answer;
}