import java.util.*;

class Solution {
    public String[] solution(String[] expressions) {
        ArrayList<String> unknownExp = new ArrayList<>();
        ArrayList<Integer> radixList = new ArrayList<>();
        
        for(String expression: expressions) {
            if(expression.contains("X")) unknownExp.add(expression);
        }
        
        for(int radix = 2;radix < 10;radix++) {
            if(validate(radix, expressions)) radixList.add(radix);
        }
        
        String[] answer = new String[unknownExp.size()];
        
        for(int i = 0;i < answer.length;i++) {
            String expression = unknownExp.get(i);
            HashSet<String> resultSet = new HashSet<>();
            String[] split = expression.split("\\s+?=\\s+?");
            String result = "";
            
            for(Integer radix: radixList) {
                int value = calc(split[0], radix);
                result = Integer.toString(value, radix);
                resultSet.add(result);
            }
            
            if(resultSet.size() == 1) {
                answer[i] = expression.replace("X", result);
            } else {
                answer[i] = expression.replace("X", "?");
            }
        }
        
        return answer;
    }
    
    public boolean validate(int radix, String[] expressions) {
        try {
            for(String expression: expressions) {
                String[] split = expression.split("\\s+?=\\s+?");
                int result = calc(split[0], radix);
                // X가 없다면 결과값이랑 비교
                if(!split[1].equals("X")) {
                    int res = Integer.parseInt(split[1], radix);
                    if(result != res) return false;
                }
            }
        } catch(NumberFormatException e) {
            return false;
        }
        return true;
    }
    
    public int calc(String expression, int radix) {
        String[] split = expression.split(" ");
        int num1 = Integer.parseInt(split[0], radix);
        int num2 = Integer.parseInt(split[2], radix);
        String op = split[1];
        
        if(op.equals("+")) {
            return num1 + num2;
        }
        return num1 - num2;
    }
}