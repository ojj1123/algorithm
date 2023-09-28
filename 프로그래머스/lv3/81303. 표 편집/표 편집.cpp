#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct Node {
    int cur;
    int left;
    int right;
    
    Node(int a, int b, int c):left(a), cur(b), right(c) {}
};

vector<Node> vec;
stack<Node> st;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    for(int i = 0;i < n;i++) {
        vec.push_back(Node(i-1, i, i+1));
    }
    
    int x;
    int curIdx = k;
    for(string str: cmd) {
        char c = str[0];
        if(c == 'U') {
            x = stoi(str.substr(2));
            for(int i = 0; i < x; i++) {
                curIdx = vec[curIdx].left;
            }
        } else if(c == 'D') {
            x = stoi(str.substr(2));
            for(int i = 0; i < x; i++) {
                curIdx = vec[curIdx].right;
            }
        } else if(c == 'C') {
            st.push(vec[curIdx]);
            int curLeft = vec[curIdx].left;
            int curRight = vec[curIdx].right;
            
            if(curLeft != -1) {
                vec[curLeft].right = curRight;
            }
            if(curRight != n) {
                vec[curRight].left = curLeft;
            }

            answer[curIdx] = 'X';
            
            if(curRight == n) {
                curIdx = curLeft;
            } else {
                curIdx = curRight;
            }
        } else if(c == 'Z') {
            Node recover = st.top();
            st.pop();
            
            int recoverLeft = recover.left;
            int recoverRight = recover.right;
            
            if(recoverLeft != -1) {
                vec[recoverLeft].right = recover.cur;
            }
            if(recoverRight != n) {
                vec[recoverRight].left = recover.cur;
            }
            answer[recover.cur] = 'O';
        }
    }

    return answer;
}