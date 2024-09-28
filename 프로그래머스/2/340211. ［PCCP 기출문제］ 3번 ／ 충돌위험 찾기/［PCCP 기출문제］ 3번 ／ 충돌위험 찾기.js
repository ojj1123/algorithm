function solution(points, routes) {
    const x = routes.length;
    const robotsPos = Array.from(Array(x), () => []);
    
    let maxRouteLen = 1;
    for(let i = 0;i < x;i++) {
        const route = routes[i];
        const len = route.length;
        
        for(let j = 1;j < len;j++) {
            const [r1, c1] = points[route[j - 1] - 1]; // from
            const [r2, c2] = points[route[j] - 1]; // to

            if(r1 > r2) {
                for(let r = r1;r > r2;r--) {
                    robotsPos[i].push([r, c1]);
                }
            } else if(r1 < r2) {
                for(let r = r1;r < r2;r++) {
                    robotsPos[i].push([r, c1]);
                }
            }
            
            if(c1 > c2) {
                for(let c = c1;c > c2;c--) {
                    robotsPos[i].push([r2, c]);
                }
            } else if(c1 < c2) {
                for(let c = c1;c < c2;c++) {
                    robotsPos[i].push([r2, c]);
                }
            }
            if(j === len - 1) {
                robotsPos[i].push([r2, c2]);
            }
        }
        
        maxRouteLen = maxRouteLen < robotsPos[i].length ? robotsPos[i].length : maxRouteLen;
    }
    
    let answer = 0;
    // 각 초마다 위치가 곂치는 것
    for(let sec = 0;sec < maxRouteLen;sec++) {
        
        // 충돌 여부 검사했는지
        let check = Array.from(Array(x), () => false);
        for(let i = 0;i < x - 1;i++) {
            if(!robotsPos[i][sec]) continue;
            if(check[i]) continue;
            
            let flag = false;
            for(let j = i + 1;j < x;j++) {
                if(!robotsPos[j][sec]) continue;
                if(check[i]) continue;
                
                const [r1, c1] = robotsPos[i][sec];
                const [r2, c2] = robotsPos[j][sec];
                
                if(r1 === r2 && c1 === c2) {
                    check[j] = true;
                    flag = true;
                }
            }
            if(flag) answer++;
        }
    }
    
    return answer;
}