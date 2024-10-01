import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int friendsLen = friends.length;
        Map<String, Integer> friendsMap = new HashMap<>();
        int[][] friendsArr = new int[friendsLen][friendsLen];
        int[][] giftScores = new int[friendsLen][2]; // { 준 선물, 받은 선물 }
        int[] acceptCount = new int[friendsLen];
        
        for(int i = 0;i < friendsLen;i++) {
            friendsMap.put(friends[i], i);
        }
        
        for(String gift: gifts) {
            String[] split = gift.split(" ");
            int a = friendsMap.get(split[0]);
            int b = friendsMap.get(split[1]);
            friendsArr[a][b]++;
        }
        
        for(int i = 0;i < friendsLen;i++) {
            int give = 0;
            int accept = 0;
            for(int j = 0;j < friendsLen;j++) {
                if(i == j) continue;
                give += friendsArr[i][j];
                accept += friendsArr[j][i];
            }
            giftScores[i][0] = give;
            giftScores[i][1] = accept;
        }
        
        for(int i = 0;i < friendsLen - 1;i++) {
            for(int j = i + 1;j < friendsLen;j++) {
                if(i == j) continue;
                // 서로 주고 받은 선물 개수 비교
                if(friendsArr[i][j] > friendsArr[j][i]) acceptCount[i]++;
                else if(friendsArr[i][j] < friendsArr[j][i]) acceptCount[j]++;
                else {
                    // 기록이 없거나 같다면
                    int score1 = giftScores[i][0] - giftScores[i][1];
                    int score2 = giftScores[j][0] - giftScores[j][1];
                    if(score1 > score2) acceptCount[i]++;
                    if(score1 < score2) acceptCount[j]++;
                }
            }
        }
        int answer = 0;
        for(int count: acceptCount) {
            answer = Math.max(answer, count);
        }
        
        return answer;
    }
}