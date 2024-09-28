function solution(video_len, pos, op_start, op_end, commands) {
    let curSec = convertToSec(pos);
    const videoSec = convertToSec(video_len)
    
    // 각 명령어를 돌면서
    for(let i = 0;i < commands.length;i++) {
        if(checkInOpRange(getTime(curSec), op_start, op_end)) {
            curSec = convertToSec(op_end);
        }
        const command = commands[i];
        switch(command) {
            case 'prev':
                if(curSec <= 10) {
                    curSec = 0;
                } else {
                    curSec = curSec - 10;
                }
                break;
            case 'next':
                if(videoSec - curSec <= 10) {
                    curSec = videoSec;
                } else {
                    curSec = curSec + 10;
                }
        }
    }
    
    if(checkInOpRange(getTime(curSec), op_start, op_end)) {
        curSec = convertToSec(op_end);
    }
    
    return getTime(curSec);
}

function checkInOpRange(pos, opStart, opEnd) {
    const posSec = convertToSec(pos);
    const opStartSec = convertToSec(opStart);
    const opEndSec = convertToSec(opEnd)
    return opStartSec <= posSec && posSec <= opEndSec;
}

function getTime(sec) {
    const mm = parseInt(sec / 60).toString().padStart(2, '0');
    const ss = (sec % 60).toString().padStart(2, '0');
    
    return mm + ':' + ss;
}


function getMMAndSS(pos) {
    return pos.split(':').map(Number);
}

function convertToSec(time) {
    const [mm, ss] = getMMAndSS(time);
    return mm * 60 + ss;
}