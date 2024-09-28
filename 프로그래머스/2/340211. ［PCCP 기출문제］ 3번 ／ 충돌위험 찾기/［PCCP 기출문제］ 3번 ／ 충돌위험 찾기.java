import java.util.*;

class Solution {
    
    public int solution(int[][] points, int[][] routes) {
        int n = points.length;
        int x = routes.length;
        
        Map<String, Integer> routeMap = new HashMap<>();
        
        for(int[] route: routes) {
            int len = route.length;
            
            int time = 0;
            for(int j = 0;j < len - 1;j++) {
                int[] cur = points[route[j] - 1];
                int[] next = points[route[j + 1] - 1];
                
                if(cur[0] > next[0]) {
                    for(int r = cur[0];r > next[0];r--) {
                        String key = makeKey(r, cur[1], time);
                        boolean has = routeMap.containsKey(key);
                        routeMap.put(key, has ? routeMap.get(key) + 1 : 1);
                        time++;
                    }
                } else if(cur[0] < next[0]) {
                    for(int r = cur[0];r < next[0];r++) {
                        String key = makeKey(r, cur[1], time);
                        boolean has = routeMap.containsKey(key);
                        routeMap.put(key, has ? routeMap.get(key) + 1 : 1);
                        time++;
                    }
                }
                
                if(cur[1] > next[1]) {
                    for(int c = cur[1];c > next[1];c--) {
                        String key = makeKey(next[0], c, time);
                        boolean has = routeMap.containsKey(key);
                        routeMap.put(key, has ? routeMap.get(key) + 1 : 1);
                        time++;
                    }
                } else if(cur[1] < next[1]) {
                    for(int c = cur[1];c < next[1];c++) {
                        String key = makeKey(next[0], c, time);
                        boolean has = routeMap.containsKey(key);
                        routeMap.put(key, has ? routeMap.get(key) + 1 : 1);
                        time++;
                    }
                }
                if(j == len - 2) {
                    String key = makeKey(next[0], next[1], time);
                    boolean has = routeMap.containsKey(key);
                    routeMap.put(key, has ? routeMap.get(key) + 1 : 1);
                }
            }
        }
        
        int answer = 0;
        for(Integer count: routeMap.values()) {
            if(count > 1) answer++;
        }
        return answer;
    }
    
    public String makeKey(int r, int c, int time) {
        return r + "," + c + "," + time;
    }
}