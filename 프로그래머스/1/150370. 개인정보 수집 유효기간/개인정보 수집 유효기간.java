import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        ArrayList<Integer> answer = new ArrayList<>();
        Map<String, Integer> termsMap = new HashMap<>();
        
        for(String term: terms) {
            String[] termArr = term.split(" ");
            termsMap.put(termArr[0], Integer.parseInt(termArr[1]));
        }

        int length = privacies.length;
        for(int i = 0;i < length;i++) {
            String[] privacy = privacies[i].split(" ");
            // 차이 계산 -> 일수로
            if(diffDay(today, privacy[0]) >= termsMap.get(privacy[1]) * 28) {
                answer.add(i + 1);
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
    
    public int diffDay(String day1, String day2) {
        String[] day1Arr = day1.split("\\.");
        String[] day2Arr = day2.split("\\.");
        
        int[] diffArr = new int[3];
        for(int i = 0;i < 3;i++) {
            diffArr[i] = Integer.parseInt(day1Arr[i]) - Integer.parseInt(day2Arr[i]);
        }
        
        int res = diffArr[0] * 28 * 12 + diffArr[1] * 28 + diffArr[2];
        return res;
    }
}