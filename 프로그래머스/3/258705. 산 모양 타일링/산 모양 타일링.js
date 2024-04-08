const mod = 10007

function solution(n, tops) {
    let answer = 0;
    let dp = Array.from(Array(2), () => Array.from(Array(2*n + 2), () => 0));
    
    dp[0][0] = dp[1][0] = 1
    
    
    for(let i = 1;i <= 2*n; i++) {
        if(i === 2*n) {
            dp[0][i] += dp[1][i-1] % mod
            dp[1][i] += dp[0][i-1] % mod
            break;
        }
        dp[0][i] += dp[1][i-1] % mod
        dp[1][i] += (dp[0][i-1] + dp[1][i-1]) % mod
        if(i % 2 === 1 && tops[parseInt(i / 2)] === 1) {
            dp[1][i] += dp[1][i-1] % mod
        }
    }
    
    answer = (dp[0][2*n] + dp[1][2*n]) % mod;
    return answer;
}