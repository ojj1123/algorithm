#include <string>
#include <vector>

using namespace std;
vector<int> arr;
int answer;

void brute(int, int, int);

int solution(vector<int> numbers, int target) {
    answer = 0;
    arr = numbers;
    brute(0, 0, target);
    
    return answer;
}

void brute(int cnt, int sum, int target) {
    if(cnt >= arr.size()) {
        if(sum == target) answer++;
        return;
    }
    brute(cnt + 1, sum + arr[cnt], target);
    brute(cnt + 1, sum - arr[cnt], target);
}