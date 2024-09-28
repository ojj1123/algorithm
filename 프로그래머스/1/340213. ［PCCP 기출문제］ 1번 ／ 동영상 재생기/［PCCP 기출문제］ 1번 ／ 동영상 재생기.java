class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        int curSec = convertToSec(pos);
        int videoSec = convertToSec(video_len);
        for(int i = 0;i < commands.length;i++) {
            if(checkInOpRange(getTime(curSec), op_start, op_end)) {
                curSec = convertToSec(op_end);
            }
            String command = commands[i];
            switch(command) {
                case "prev":
                    if(curSec <= 10) {
                        curSec = 0;
                    } else {
                        curSec -= 10;
                    }
                    break;
                case "next":
                    if(videoSec - curSec <= 10) {
                        curSec = videoSec;
                    } else {
                        curSec += 10;
                    }
            }
        }
        
        if(checkInOpRange(getTime(curSec), op_start, op_end)) {
            curSec = convertToSec(op_end);
        }
        
        return getTime(curSec);
    }
    
    public int convertToSec(String time) {
        String[] converted = time.split(":");
        return Integer.parseInt(converted[0]) * 60 + Integer.parseInt(converted[1]);
    }
    
    public boolean checkInOpRange(String pos, String opStart, String opEnd) {
        int posSec = convertToSec(pos);
        int opStartSec = convertToSec(opStart);
        int opEndSec = convertToSec(opEnd);
        return opStartSec <= posSec && posSec <= opEndSec;
    }
    
    public String getTime(int sec) {
        int mm = sec / 60;
        int ss = sec % 60;
        String mmStr = mm < 10 ? '0' + Integer.toString(mm) : Integer.toString(mm);
        String ssStr = ss < 10 ? '0' + Integer.toString(ss) : Integer.toString(ss);
        
        return mmStr + ':' + ssStr;
    }
}