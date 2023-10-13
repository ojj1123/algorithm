#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool isCheck[10];
vector<int> graph[10];
unordered_set<string> dedup;

void brute(int, int);

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int userLen = user_id.size();
    int bannedLen = banned_id.size();
    
    for(int k = 0;k < bannedLen;k++) {
        int bannedUserNameLen = banned_id[k].length();
        for(int num = 0;num < userLen;num++) {
            int userNameLen = user_id[num].length();
            if(bannedUserNameLen != userNameLen) continue;
            
            bool flag = true;
            for(int i = 0;i < userNameLen;i++) {
                if(banned_id[k][i] == '*') continue;
                if(banned_id[k][i] != user_id[num][i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                graph[k].push_back(num);
            }
        }
    }
    brute(bannedLen, 0);
    answer = dedup.size();
    return answer;
}

string str = "";
void brute(int total, int curIdx) {
    if(curIdx >= total) {
        string temp = str;
        sort(temp.begin(), temp.end());
        dedup.insert(temp);
        return;
    }
    
    for(int i = 0;i < graph[curIdx].size();i++) {
        int user = graph[curIdx][i];
        if(isCheck[user]) continue;
        isCheck[user] = true;
        str += to_string(user);
        brute(total, curIdx + 1);
        str.pop_back();
        isCheck[user] = false;
    }
}