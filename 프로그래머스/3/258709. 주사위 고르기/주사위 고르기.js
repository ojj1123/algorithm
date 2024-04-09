

function solution(dice) {
    let answer = [];
    let n = dice.length;
    let isUsed = Array.from(Array(n), () => false)
    let arrA = []
    let arrB = []
    let order = []
    let maxVal = 0
    
    brute(0, 0);
    
    // 어떤 주사위 사용할지
    function brute(cur, cnt) {
        if(cnt >= n / 2) {
            arrA = []
            arrB = []
            calculateDiceSum(0)
            
            arrA.sort(compare)
            arrB.sort(compare)
            
            let startB = 0
            
            let count = 0
            for(let i = 0;i < arrA.length;i++) {
                while(startB < arrB.length) {
                    if(arrA[i] > arrB[startB]) {
                        break
                    }
                    startB++
                }
                if(startB === arrB.length) {
                    count += 0
                } else {
                    count += arrB.length - startB
                }
            }
            console.log(count)
            if(maxVal < count) {
                maxVal = count
                answer = []
                for(let i = 0;i < n;i++) {
                    if(!isUsed[i]) continue;
                    answer.push(i + 1)
                }
            }
            
            return;
        }
        for(let i = cur; i < n; i++) {
            isUsed[i] = true
            brute(i + 1, cnt + 1)
            isUsed[i] = false
        }
    }
    
    // 선택한 주사위에서 나올 수 있는 경우의 수(굴린 주사위 합) 모두 구하기
    function calculateDiceSum(cnt) {
        if(cnt >= n / 2) {
            let startA = 0
            let startB = 0
            let sumA = 0
            let sumB = 0
            for(let i = 0;i < n;i++) {
                if(isUsed[i]) { // A
                    sumA += dice[i][order[startA++]]
                } else { // B
                    sumB += dice[i][order[startB++]]
                }
            }
            arrA.push(sumA)
            arrB.push(sumB)
            return
        }
        
        for(let i = 0;i < 6;i++) {
            order.push(i)
            calculateDiceSum(cnt + 1)
            order.pop();
        }
    }
    
    return answer;
}

function compare(a, b) {
    if(a < b) return 1
    if(a === b) return 0
    if(a > b) return -1
}