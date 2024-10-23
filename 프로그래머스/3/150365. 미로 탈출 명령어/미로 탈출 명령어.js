const dx = [1, 0, 0, -1];
const dy = [0, -1, 1, 0];
const dirStr = ['d', 'l', 'r', 'u'];

function solution(n, m, x, y, r, c, k) {
    let answer = '';
    
    brute(0, k, x, y, '');
    
    function brute(curK, remainK, curX, curY, path) {
        if(answer != '') return;
        if(curK >= k) { // k번 이동 완료
            if(curX == r && curY == c) {
                answer = path;
            }
            return;
        }
        const dist = getDist(curX, curY, r, c);
        if(dist > remainK) {
            return;
        }
        if((dist % 2 == 0 && remainK % 2 == 1) || (dist % 2 == 1 && remainK % 2 == 0)) {
            return;
        }

        for(let dir = 0;dir < 4;dir++) {
            if(answer != '') return;
            const nx = curX + dx[dir];
            const ny = curY + dy[dir];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            brute(curK + 1, remainK - 1, nx, ny, path + dirStr[dir]);
        }
    }
    
    return answer == '' ? 'impossible' : answer;
}

function getDist(x1, y1, x2, y2) {
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
}