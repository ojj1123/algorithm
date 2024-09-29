function solution(bandage, health, attacks) {
    let curHealth = health;
    let consisCount = 0;
    const attacksLen = attacks.length;
    const [t, x, y] = bandage;
    
    curHealth -= attacks[0][1];
    
    for(let i = 1;i < attacksLen;i++) {
        if(curHealth <= 0) return -1;
        const [prevTime] = attacks[i - 1];
        const [time, attack] = attacks[i];
        
        // 회복량 계산
        const count = time - prevTime - 1;
        const recov = parseInt(count / t) * y + count * x;
        curHealth = curHealth + recov >= health ? health : curHealth + recov;
        // 체력 줄고
        curHealth -= attack;
    }
    
    if(curHealth <= 0) return -1;
    return curHealth;
}