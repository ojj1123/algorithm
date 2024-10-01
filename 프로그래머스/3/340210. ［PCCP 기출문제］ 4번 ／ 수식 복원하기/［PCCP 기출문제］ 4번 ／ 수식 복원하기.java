import java.util.*;

class Solution {
    public String[] solution(String[] expressions) {
        ArrayList<String> answer = new ArrayList<>();
        boolean[] check = new boolean[10];
        Arrays.fill(check, true);
        
        for(String expression: expressions) {
            String[] arr = expression.split(" \\+ | - | = ");
            boolean[] checkEach = new boolean[10];
            Arrays.fill(checkEach, false);
            
            for(int radix = 2;radix <= 9;radix++) {
                // 해당 수식이 해당 진법이 가능한가?
                boolean flag = false;
                for(int j = 0;j < arr.length;j++) {
                    if(arr[j].equals("X")) continue;
                    if(!canUseRadix(arr[j], radix)) {
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                // 정답이 없는 경우) 해당 진법 가능함
                if(arr[2].equals("X")) {
                    checkEach[radix] = true;
                    continue;
                }
                // 정답이 있는 경우) 가능한 진법으로 정답도 동일한가?
                String res = "";
                if(expression.contains("+")) {
                    res = Integer.toString(Integer.parseInt(arr[0], radix) + Integer.parseInt(arr[1], radix), radix);
                } else {
                    res = Integer.toString(Integer.parseInt(arr[0], radix) - Integer.parseInt(arr[1], radix), radix);
                }
                checkEach[radix] = res.equals(arr[2]);
            }
            for(int radix = 2;radix <= 9;radix++) {
                check[radix] = check[radix] && checkEach[radix];
            }
        }
        
        for(String exp: expressions) {
            if(!exp.contains("X")) continue;
            
            String[] arr = exp.split(" \\+ | - | = ");
            HashSet<String> valSet = new HashSet<>();
            
            for(int radix = 2;radix <= 9;radix++) {
                if(!check[radix]) continue;
                
                String res = "";
                if(exp.contains("+")) {
                    res = Integer.toString(Integer.parseInt(arr[0], radix) + Integer.parseInt(arr[1], radix), radix);
                } else {
                    res = Integer.toString(Integer.parseInt(arr[0], radix) - Integer.parseInt(arr[1], radix), radix);
                }
                valSet.add(res);
            }
            
            ArrayList<String> list = new ArrayList<>(valSet);
            if(list.size() == 1) {
                answer.add(exp.replace("X", list.get(0)));
            } else {
                answer.add(exp.replace("X", "?"));
            }
        }
        
        return answer.toArray(new String[answer.size()]);
    }
    
    public boolean canUseRadix(String numStr, int radix) {
        for(int i = 0;i < numStr.length();i++) {
            if(numStr.charAt(i) - '0' >= radix) return false;
        }
        return true;
    }
}