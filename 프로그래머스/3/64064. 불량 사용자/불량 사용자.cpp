#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool isCheck[10];
unordered_set<string> dedup;

void brute(vector<string>, vector<string>, int);
bool check(string, string);

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    brute(user_id, banned_id, 0);
    answer = dedup.size();
    return answer;
}

string str = "";
void brute(vector<string> user_id, vector<string> banned_id, int curIdx) {
    if(curIdx >= banned_id.size()) {
        string temp = str;
        sort(temp.begin(), temp.end());
        dedup.insert(temp);
        return;
    }
    
    for(int i = 0;i < user_id.size();i++) {
        if(isCheck[i] || !check(user_id[i], banned_id[curIdx])) continue;
        isCheck[i] = true;
        str += to_string(i);
        brute(user_id, banned_id, curIdx + 1);
        str.pop_back();
        isCheck[i] = false;
    }
}

bool check(string user, string bannedUser) {
    int userLen = user.length();
    int bannedUserLen = bannedUser.length();
    if(userLen != bannedUserLen) return false;
    for(int i = 0;i < userLen;i++) {
        if(bannedUser[i] == '*') continue;
        if(bannedUser[i] != user[i]) return false;
    }
    return true;
}