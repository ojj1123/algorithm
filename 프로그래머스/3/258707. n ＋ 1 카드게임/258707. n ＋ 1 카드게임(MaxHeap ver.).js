class MaxHeap {
  #heap;
  constructor(heap = []) {
    this.#heap = [];
    heap.forEach((x) => this.add(x));
  }

  isEmpty() {
    return this.#heap.length === 0;
  }

  size() {
    return this.#heap.length;
  }

  top() {
    if (this.isEmpty()) throw new Error('the heap is empty');
    return this.#heap[0];
  }

  pop() {
    if (this.isEmpty()) throw new Error('the heap is empty');
    let last = this.#heap[this.#heap.length - 1];
    this.#heap[0] = last;
    this.#heap.pop();
    this.#bubbleDown();
  }

  add(x) {
    this.#heap.push(x);
    this.#bubbleUp();
  }

  #bubbleUp() {
    let i = this.#heap.length - 1;

    while (i > 0) {
      const parentIndex = this.getParentIndex(i);
      if (this.#heap[parentIndex] >= this.#heap[i]) break;
      this.swap(parentIndex, i);
      i = parentIndex;
    }
  }

  #bubbleDown() {
    let i = 0;

    // 예외상황 생각해보기
    // i번째 노드의 left, right 가 없을 수도 있음
    while (
      (this.hasLeftChild(i) &&
        this.#heap[i] < this.#heap[this.getLeftChildIndex(i)]) ||
      (this.hasRightChild(i) &&
        this.#heap[i] < this.#heap[this.getRightChildIndex(i)])
    ) {
      const leftChildIndex = this.getLeftChildIndex(i);
      const rightChildIndex = this.getRightChildIndex(i);
      const left = this.#heap[leftChildIndex];
      const right = this.#heap[rightChildIndex];

      if (this.hasLeftChild(i) && this.hasRightChild(i)) {
        if (left >= right) {
          this.swap(leftChildIndex, i);
          i = leftChildIndex;
        } else {
          this.swap(rightChildIndex, i);
          i = rightChildIndex;
        }
      } else if (this.hasLeftChild(i)) {
        this.swap(leftChildIndex, i);
        i = leftChildIndex;
      }
    }
  }

  getLeftChildIndex(index) {
    return 2 * index + 1;
  }

  getRightChildIndex(index) {
    return 2 * index + 2;
  }

  getParentIndex(index) {
    return Math.floor((index - 1) / 2);
  }

  hasLeftChild(index) {
    return this.getLeftChildIndex(index) < this.size();
  }

  hasRightChild(index) {
    return this.getRightChildIndex(index) < this.size();
  }

  toString() {
    return this.#heap.toString();
  }

  swap(index1, index2) {
    let temp = this.#heap[index1];
    this.#heap[index1] = this.#heap[index2];
    this.#heap[index2] = temp;
  }
}

function solution(coin, cards) {
    let answer = 1;
    const n = cards.length;
    const nP1 = n + 1;
    const heap = new MaxHeap();
    const usedCoin = new Map();
    
    for(let i = 0;i < n / 3;i++) {
        if(usedCoin.has(nP1 - cards[i])) {
            heap.add(0);
            usedCoin.delete(nP1 - cards[i]);
        } else {
            usedCoin.set(cards[i], 0);
        }
    }
    
    for(let i = n / 3;i < n;i += 2) {
        for(let j = 0;j < 2;j++) {
            if(usedCoin.has(nP1 - cards[i + j])) {
                heap.add(usedCoin.get(nP1 - cards[i + j]) - 1);
                usedCoin.delete(nP1 - cards[i + j]);
            } else {
                usedCoin.set(cards[i + j], -1);
            }
        }
        
        if(heap.isEmpty() || coin + heap.top() < 0) {
            break;
        }
        coin += heap.top();
        heap.pop();
        answer++;
    }
    
    
    return answer;
}
