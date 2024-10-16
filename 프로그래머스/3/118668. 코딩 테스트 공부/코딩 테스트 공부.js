const MAX = 1000000000;
function solution(alp, cop, problems) {
    let curCop = cop;
    let n = problems.length;
    // 최초 alp, cop 가 maxAlp, maxCop 보다 무조건 작다는 조건이 없기 때문에 alp, cop로 초기화
    let maxAlp = alp;
    let maxCop = cop;
    problems.forEach(([areq, creq]) => {
        maxAlp = Math.max(maxAlp, areq);
        maxCop = Math.max(maxCop, creq);
    })
    const dp = Array.from(Array(maxAlp + 2), () => Array.from(Array(maxCop + 2), () => MAX));

    dp[alp][cop] = 0;
    
    for(let i = alp;i <= maxAlp;i++) {
        for(let j = cop;j <= maxCop;j++) {
            for(const [areq, creq, arwd, crwd, cost] of problems) {
                // 문제 안 풀고 알고력, 코딩력 1씩 올리는게 더 나은 경우
                if(cost >= arwd + crwd) continue;
                if(i >= areq && j >= creq) { // 풀 수 있는 경우
                    const curAlp = Math.min(i + arwd, maxAlp);
                    const curCop = Math.min(j + crwd, maxCop);
                    dp[curAlp][curCop] = Math.min(dp[curAlp][curCop], dp[i][j] + cost);
                }
            }
            
            dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + 1);
        }
    }
    
    return dp[maxAlp][maxCop];
}