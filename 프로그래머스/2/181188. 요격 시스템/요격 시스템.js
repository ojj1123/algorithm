function solution(targets) {
    let answer = 0;
    let len = targets.length
    let check = Array.from(Array(len), () => false)
    targets.sort(compare)
    
    for(let i = 0;i < len;i++) {
        // 요격 된 경우
        if(check[i]) continue
        const [, e] = targets[i]
        // 요격 안된 경우
        for(let j = i+1;j < len && e > targets[j][0];j++) {
            if(check[j]) continue
            check[j] = true
        }
        check[i] = true
        answer++
    }

    return answer;
}

function compare(a, b) {
    if(a[1] > b[1]) return 1;
    if(a[1] < b[1]) return -1;
    if(a[1] === b[1]) return 0;
}