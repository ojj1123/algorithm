#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int total;
int ans;
bool isUsed[10];
vector<vector<int>> dungeonsCopy;

void brute(int, int);

int solution(int k, vector<vector<int>> dungeons) {
    total = dungeons.size();
    dungeonsCopy = dungeons;
    brute(k, 0);
    return ans;
}

void brute(int k, int cnt) {
    // 다 돌았을 경우
    if(cnt >= total) {
        ans = max(ans, cnt);
        return;
    }
    
    for(int i = 0;i < total; i++) {
        if(isUsed[i]) continue;
        if(k < dungeonsCopy[i][0]) continue;
        isUsed[i] = true;
        brute(k - dungeonsCopy[i][1], cnt + 1);
        isUsed[i] = false;
    }
    // 다 못돌았을 경우
    ans = max(ans, cnt);
    return;
}