#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> alpha = {"A", "E", "I", "O", "U"};
vector<string> result;

void brute(int,int,string);

int solution(string word) {
    int answer = 0;
    for(int i=1;i<=5;i++) {
        brute(i, 0, "");
    }
    sort(result.begin(), result.end());
    
    for(int i=0;i<result.size();i++) {
        if(word.compare(result[i]) == 0) return i + 1;
    }
    // return answer;
}

// cnt - 문자 개수, k - 지금까지 추가한 문자 개수
void brute(int cnt, int k, string str) {
    if(k >= cnt) {
        result.push_back(str);
        return;
    }
    
    for(int i=0;i<5;i++) {
        str += alpha[i];
        brute(cnt, k+1, str);
        str.pop_back();
    }
}