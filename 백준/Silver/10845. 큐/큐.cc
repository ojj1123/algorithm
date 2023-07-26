#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

const int MAX = 10000;
int myQueue[MAX + 2];
int lpt, rpt;
int n, num;
string operation;

void push(int);
int pop();
int size();
int empty();
int front();
int back();

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
		else if (operation.compare("front") == 0) cout << front() << endl;
		else if (operation.compare("back") == 0) cout << back() << endl;
	}
}

void push(int num) {
	myQueue[rpt++] = num;
}

int pop() {
	return size() == 0 ? -1 : myQueue[lpt++];
}

int size() {
	return rpt - lpt;
}

int empty() {
	return size() == 0 ? 1 : 0;
}

int front() {
	return size() == 0 ? -1 : myQueue[lpt];
}

int back() {
	return size() == 0 ? -1 : myQueue[rpt - 1];
}