import java.util.*;

class Solution {
    ArrayList<Integer> discounts = new ArrayList<>();
    int[] answer = new int[] {-1, -1};
    
    public int[] solution(int[][] users, int[] emoticons) {
        int n = users.length;
        int m = emoticons.length;
        
        brute(m, 0, users, emoticons);
        
        return answer;
    }
    
    public void brute(int m, int cur, int[][] users, int[] emoticons) {
        if(cur >= m) {
            
            int totalSum = 0;
            int serviceCount = 0;
            
            for(int i = 0;i < users.length;i++) {
                int[] user = users[i];
                
                int sum = 0;
                for(int j = 0;j < m;j++) {
                    if(discounts.get(j) >= user[0]) {
                        sum += emoticons[j] * (100 - discounts.get(j)) / 100;
                    }
                }
                if(sum >= user[1]) {
                    // 안삼 -> 서비스 가입
                    serviceCount++;
                } else {
                    totalSum += sum;
                }
            }
            
            if(answer[0] == -1 && answer[1] == -1) {
                answer[0] = serviceCount;
                answer[1] = totalSum;
            } else {
                if(answer[0] < serviceCount) {
                    answer[0] = serviceCount;
                    answer[1] = totalSum;
                } else if(answer[0] == serviceCount) {
                    if(answer[1] < totalSum) {
                        answer[0] = serviceCount;
                        answer[1] = totalSum;
                    }
                }
            }
            
            return;
        }
        
        for(int dis = 10;dis <= 40;dis+=10) {
            discounts.add(dis);
            brute(m, cur + 1, users, emoticons);
            discounts.remove(discounts.size() - 1);
        }
        
    }
}