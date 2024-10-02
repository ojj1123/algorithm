import java.util.*;

class Solution {
    String[][] personality = {
        {"R", "T"},
        {"C", "F"},
        {"J", "M"},
        {"A", "N"}
    };
    Map<String, Integer> countMap;
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int n = choices.length;
        
        initialize();
        
        for(int i = 0;i < n;i++) {
            if(choices[i] == 4) continue;
            
            String[] splits = survey[i].split("");
            int isAgreed = choices[i] / 4;
            int score = Math.abs(choices[i] - 4);
            String type = splits[isAgreed];
            if(countMap.containsKey(type)) {
                Integer prev = countMap.get(type);
                countMap.put(type, prev + score);
            } else {
                countMap.put(type, score);
            }
        }
        
        for(int i = 0;i < 4;i++) {
            String[] types = personality[i];
            if(countMap.get(types[0]) >= countMap.get(types[1])) {
                answer += types[0];
            } else {
                answer += types[1];
            }
        }
        
        return answer;
    }
    
    public void initialize() {
        countMap = new HashMap<>();
        for(int i = 0;i < 4;i++) {
            countMap.put(personality[i][0], 0);
            countMap.put(personality[i][1], 0);
        }
    }
}