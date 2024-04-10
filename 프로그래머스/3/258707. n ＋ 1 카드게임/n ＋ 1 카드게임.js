function solution(coin, cards) {
    let answer = 0;
    let cur;
    let arr = new Set();
    let n = cards.length;
    
    cur = new Set(cards.slice(0, n / 3))
    

    let flag1 = false, flag2 = false, flag3 = false
    let isLast = false
    for(let i = n / 3;i < n - 1;i+=2) {
        answer++;
        isLast = i === n - 2
        
        arr.add(cards[i])
        arr.add(cards[i+1])
        
        flag1 = false, flag2 = false, flag3 = false
        
        flag1 = false
        for(let value of cur.values()) {
            const found = n + 1 - value
            if(cur.has(found)) {
                cur.delete(value);
                cur.delete(found);
                flag1 = true
                break;
            }
        }
        
        if(flag1) continue
        // 동전이 없고 손에 있는 카드에서 불가능하면
        if(coin === 0) break;
        
        flag2 = false
        for(let value of cur.values()) {
            const found = n + 1 - value
            if(arr.has(found)) {
                cur.delete(value);
                arr.delete(found);
                coin--;
                flag2 = true
                break;
            }
        }
        if(flag2) continue
        // 동전이 1개 이하고 손에 있는 카드 1장과 뽑을 카드 1장으로도 불가능하면
        if(coin <= 1) break;
        
        flag3 = false
        for(let value of arr.values()) {
            const found = n + 1 - value
            if(arr.has(found)) {
                arr.delete(value);
                arr.delete(found);
                coin-=2;
                flag3 = true
                break;
            }
        }
        
        // 셋다 불가능하면
        if(!flag3) break;
    }
    
    if((flag1 || flag2 || flag3) && isLast) {
        // 셋 중에 하나라도 가능한 경우
        answer++
    }
    
    return answer;
}