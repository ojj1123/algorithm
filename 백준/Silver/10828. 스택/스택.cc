#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
#define endl '\n'

const int MAX = 10000;
int stack[MAX + 2];
int pointer;
int n, num;
string operation;

void push(int);
int pop();
int size();
int empty();
int top();

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> operation;

		
		if (operation.compare("push") == 0) {
			cin >> num;
			push(num);
		}
		else if (operation.compare("pop") == 0) cout << pop() << endl;
		else if (operation.compare("size") == 0) cout << size() << endl;
		else if (operation.compare("empty") == 0) cout << empty() << endl;
		else if (operation.compare("top") == 0) cout << top() << endl;
	}
}

void push(int num) {
	stack[pointer++] = num;
}

int pop() {
	return pointer == 0 ? -1 : stack[--pointer];
}

int size() {
	return pointer;
}

int empty() {
	return pointer == 0 ? 1 : 0;
}

int top() {
	return pointer == 0 ? -1 : stack[pointer - 1];
}