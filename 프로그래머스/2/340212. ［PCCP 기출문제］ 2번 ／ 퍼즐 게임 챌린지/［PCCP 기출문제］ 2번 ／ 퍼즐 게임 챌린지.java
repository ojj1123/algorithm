class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int maxDiff = 1;
        for(int i = 0;i < diffs.length;i++) {
            maxDiff = diffs[i] > maxDiff ? diffs[i] : maxDiff;
        }
        
        int start = 1;
        int end = maxDiff;
        
        while(start < end) {
            int level = (start + end) / 2;
            if(isOverLimit(level, diffs, times, limit)) {
                start = level + 1;
            } else {
                end = level;
            }
        }
        
        return start;
    }
    
    public boolean isOverLimit(int level, int[] diffs, int[] times, long limit) {
        int n = diffs.length;
        
        long sum = times[0];
        for(int i = 1;i < n;i++) {
            if(diffs[i] > level) {
                sum += (diffs[i] - level) * (times[i - 1] + times[i]) + times[i];
            } else {
                sum += times[i];
            }
        }
        
        return sum > limit;
    }
}