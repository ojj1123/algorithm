let dx = [1, 0, -1, 0];
let dy = [0, 1, 0, -1];

function solution(maze) {
    const n = maze.length;
    const m = maze[0].length;
    let redStart, redEnd, blueStart, blueEnd;
    const visRed = Array.from(Array(n), () => Array.from(Array(m), () => -1));
    const visBlue = Array.from(Array(n), () => Array.from(Array(m), () => -1));
    
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            const pos = {r: i, c: j};
            if(maze[i][j] === 1) redStart = pos;
            else if(maze[i][j] === 2) blueStart= pos;
            else if(maze[i][j] === 3) redEnd = pos;
            else if(maze[i][j] === 4) blueEnd = pos;
        }
    }
    
    let answer = -1;

    visRed[redStart.r][redStart.c] = 0;
    dfsRed(redStart)
    
    function dfsRed({r, c}) {
        // 도착지점이면 -> dfsBlue
        if(r === redEnd.r && c === redEnd.c) {
            visBlue[blueStart.r][blueStart.c] = 0;
            dfsBlue(blueStart);
            visBlue[blueStart.r][blueStart.c] = -1;
            return;
        }
        
        for(let dir = 0;dir < 4;dir++) {
            const nx = r + dx[dir];
            const ny = c + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maze[nx][ny] === 5) continue;
            // 이미 지나온 길이라면
            if(visRed[nx][ny] !== -1) continue;
            
            visRed[nx][ny] = visRed[r][c] + 1;
            dfsRed({r: nx, c: ny});
            visRed[nx][ny] = -1;
        }
    }

    function dfsBlue({r, c}) {
        // 도착지점이면 -> 카운트 최소 계산
        if(r === blueEnd.r && c === blueEnd.c) {
            const value = Math.max(visRed[redEnd.r][redEnd.c], visBlue[blueEnd.r][blueEnd.c]);
            answer = answer === -1 ? value : Math.min(answer, value);
            return;
        }
        for(let dir = 0;dir < 4;dir++) {
            const nx = r + dx[dir];
            const ny = c + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
             // if wall
            if(maze[nx][ny] === 5) continue;
            
            // 블루가 이미 지나온 경우
            if(visBlue[nx][ny] !== -1) continue;
            
            // 충돌하는 경우
            if(visBlue[r][c] + 1 === visRed[nx][ny]) continue;
            
            // 서로 교차하는 경우
            if(visBlue[r][c] === visRed[nx][ny] && visBlue[r][c] + 1 === visRed[r][c]) continue;
            
            // 다음이 블루 도착인데 레드가 블루 방문순서 이후에 지나가려고 하면
            if(nx === blueEnd.r && ny === blueEnd.c && visBlue[r][c] + 1 <= visRed[nx][ny]) continue;
            
            // 다음이 레드 도착인데 블루가 레드 방문순서 이후에 지나가려고 하면
            if(nx === redEnd.r && ny === redEnd.c && visBlue[r][c] + 1 >= visRed[nx][ny]) continue;
            
            visBlue[nx][ny] = visBlue[r][c] + 1;
            dfsBlue({r: nx, c: ny});
            visBlue[nx][ny] = -1;
        }
    }
    
    return answer === -1 ? 0 : answer;
}

