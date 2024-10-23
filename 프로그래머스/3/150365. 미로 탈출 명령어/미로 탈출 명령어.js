const dx = [1, 0, 0, -1];
const dy = [0, -1, 1, 0];
const dirStr = ['d', 'l', 'r', 'u'];

function solution(n, m, x, y, r, c, k) {
    let answer = '';
    
    if(!possible(x, y, r, c, k)) return 'impossible';
    
    let curX = x;
    let curY = y;
    let curK = k;
    while(curK > 0) {
        for(let dir = 0;dir < 4;dir++) {
            const nx = curX + dx[dir];
            const ny = curY + dy[dir];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(possible(nx, ny, r, c, curK - 1)) {
                answer += dirStr[dir];
                curX = nx;
                curY = ny;
                curK--;
                break;                
            }
        }
    }
    
    return answer;
}

function possible(x, y, r, c, k) {
    const distance = Math.abs(x - r) + Math.abs(y - c);
    if(distance > k) return false;
    if(distance == k) return true;
    if(distance % 2 != k % 2) return false;
    return true;
}