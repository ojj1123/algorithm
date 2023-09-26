#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
map<string, pair<int,int>> check;
int maxCntPerStrlen[12];
bool checkCourseCnt[12];
void getComb(string, int, string, int, int, int);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int courseLen = course.size();
    for(int i = 0;i < courseLen;i++) {
        checkCourseCnt[course[i]] = true;
    }
    int len = orders.size();
    for(int i = 0;i < len;i++) {
        sort(orders[i].begin(), orders[i].end());
        // cout<<orders[i]<<endl;
        int orderLen = orders[i].length();
        for(int j = 2;j <= orderLen;j++) {
            getComb(orders[i], orderLen, "", j, 0, 0);
        }
    }
    
    for(auto item: check) {
        int cnt = item.second.first;
        int strLen = item.second.second;
        maxCntPerStrlen[strLen] = max(maxCntPerStrlen[strLen], cnt);
    }
    
    for(auto item: check) {
        string str = item.first;
        int cnt = item.second.first;
        int strLen = item.second.second;
        if(maxCntPerStrlen[strLen] >= 2 && checkCourseCnt[strLen] && maxCntPerStrlen[strLen] == cnt) {
            answer.push_back(str);
        }
    }
    
    return answer;
}

void getComb(string order, int orderLen, string str, int m, int cnt, int cur) {
    if(cnt >= m) {
        if(check.find(str) != check.end()) {
            check[str].first++;
        } else {
            check[str].first = 1;
            check[str].second = m;
        }
        return;
    }
    for(int i = cur;i < orderLen;i++) {
        str += order[i];
        getComb(order, orderLen, str, m, cnt + 1, i + 1);
        str.pop_back();
    }
}