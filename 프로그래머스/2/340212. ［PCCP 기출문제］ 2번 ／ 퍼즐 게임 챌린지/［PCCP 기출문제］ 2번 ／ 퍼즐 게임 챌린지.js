function solution(diffs, times, limit) {
    let maxDiff = 1;
    diffs.forEach((v) => {
        maxDiff = v > maxDiff ? v : maxDiff;
    });
    
    let start = 1;
    let end = maxDiff;

    while(start < end) {
        let level = parseInt((start + end) / 2);
        if(isOverLimit(level, diffs, times, limit)) {
            start = level + 1;
        } else {
            end = level;
        }
    }
    
    return start;
}

function isOverLimit(level, diffs, times, limit) {
    const n = diffs.length;
    
    let sum = times[0];
    for(let i = 1;i < n;i++) {
        if(diffs[i] > level) {
            sum += (diffs[i] - level) * (times[i - 1] + times[i]) + times[i];
        } else {
            sum += times[i]
        }
    }
    
    return sum > limit;
}