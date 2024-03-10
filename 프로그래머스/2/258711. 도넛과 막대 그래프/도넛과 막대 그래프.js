let inoutCnt = new Map();

function solution(edges) {
    let answer = [];
    
    init(edges)

    const start = getStartVertex()
    
    const edgesFromStart = getEdgesFromStart(start, edges)
    
    updateGraph(start, edgesFromStart)
    
    const res = countGraph(start, edgesFromStart)
    
    answer = [start, ...res]
    
    return answer;
}

function init(edges) {
    edges.forEach(([a, b]) => {
        if(inoutCnt.has(a)) {
            const prev = inoutCnt.get(a)
            inoutCnt.set(a, {...prev, out: prev.out+1})
        } else {
            inoutCnt.set(a, {in: 0, out: 1})
        }
        
        if(inoutCnt.has(b)) {
            const prev = inoutCnt.get(b)
            inoutCnt.set(b, {...prev, in: prev.in+1})
        } else {
            inoutCnt.set(b, {in: 1, out: 0})
        }
    })
}

function getStartVertex() {
    for(let vertex of inoutCnt.entries()) {
        const [num, cnt] = vertex
        if(cnt.in === 0 && cnt.out >= 2) {
            return num
        }
    }
}

function getEdgesFromStart(start, edges) {
    const res = []
    edges.forEach(([a, b]) => {
        if(start === a) res.push(b)
    })
    return res
}

function updateGraph(start, edges) {
    
    edges.forEach((next) => {
        const prev = inoutCnt.get(next)
        inoutCnt.set(next, {...prev, in: prev.in - 1})
    })
}

function countGraph(start, edges) {
    const totalEdge = edges.length
    let res = [0, 0, 0]
    
    for(let vertex of inoutCnt.entries()) {
        const [num, cnt] = vertex
        if(num === start) continue
        if(isStick(cnt)) res[1]++
        else if(isEight(cnt)) res[2]++
    }
    res[0] = totalEdge - (res[1] + res[2])
    return res
}

function isStick(cnt) {
    return (cnt.in === 0 && cnt.out === 0) || (cnt.in === 0 && cnt.out === 1)
}
    
function isEight(cnt) {
    return cnt.in === 2 && cnt.out === 2
}