const H_TO_S = 3600
const M_TO_S = 60

function solution(h1, m1, s1, h2, m2, s2) {
    let answer = 0
    const start = getSec(h1, m1, s1)
    const end = getSec(h2, m2, s2)
    
    for(let i = start; i < end;i++) {
        const curAngles = getAngles(i)
        const nextAngles = getAngles(i + 1)
        
        const isMinute = isMinuteMatched(curAngles, nextAngles)
        const isHour = isHourMatched(curAngles, nextAngles)
        
        if(isMinute && isHour) {
            if(nextAngles.m === nextAngles.h) answer++
            else answer += 2
        } else if(isMinute || isHour) {
            answer++
        }
    }
    
    if(start === 0 || start === 43200) answer++
    return answer;
}

function getSec(h, m, s) {
    return h*H_TO_S + m*M_TO_S + s
}

function getTime(sec) {
    const h = parseInt(sec / H_TO_S)
    const m = parseInt((sec % H_TO_S) / M_TO_S)
    const s = parseInt((sec % H_TO_S) % M_TO_S)
    return {h, m, s}
}

function getAngles(sec) {
    const time = getTime(sec)
    const h = (time.h%12)*30 + time.m*0.5 + time.s*(1/120)
    const m = time.m*6 + time.s*0.1
    const s = time.s*6
    return {h, m, s}
}

function isMinuteMatched(cur, next) {
    if(cur.s < cur.m && next.s >= next.m) return true
    
    if(cur.s === 354 && cur.m > 354) return true
    return false
}

function isHourMatched(cur, next) {
    if(cur.s < cur.h && next.s >= next.h) return true
    
    if(cur.s === 354 && cur.h > 354) return true
    return false
}