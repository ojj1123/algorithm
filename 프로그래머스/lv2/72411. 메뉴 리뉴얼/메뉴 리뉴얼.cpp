#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
map<string, int> check;
int maxCntPerStrlen[12];

void combination(string, string, int, int);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string &order: orders) {
        sort(order.begin(), order.end());
    }
    
    for(string order: orders) {
        for(int cnt: course) {
            combination(order, "", cnt, 0);
        }
    }
    
    for(auto item: check) {
        int len = item.first.length();
        int cnt = item.second;
        maxCntPerStrlen[len] = max(maxCntPerStrlen[len], cnt);
    }
    
    for(auto item: check) {
        string str = item.first;
        int len = str.length();
        int cnt = item.second;
        if(maxCntPerStrlen[len] >= 2 && maxCntPerStrlen[len] == cnt) {
            answer.push_back(str);
        }
    }
    
    return answer;
}

void combination(string order, string course, int cnt, int cur) {
    if(course.length() >= cnt) {
        if(check.find(course) != check.end()) {
            check[course]++;
        } else {
            check[course] = 1;
        }
        return;
    }
    for(int i = cur;i < order.length();i++) {
        course += order[i];
        combination(order, course, cnt, i + 1);
        course.pop_back();
    }
}